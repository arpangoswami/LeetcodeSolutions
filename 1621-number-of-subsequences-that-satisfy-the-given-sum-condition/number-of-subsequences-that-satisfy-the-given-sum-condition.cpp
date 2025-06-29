using ll = long long;
class Solution {
    constexpr static ll MOD = 1e9+7;
    ll getPower(ll x,ll pow){
        ll ans = 1;
        while(pow > 0){
            if(pow & 1){
                ans *= x;
                ans %= MOD;
            }
            x *= x;
            x %= MOD;
            pow >>= 1;
        }
        return ans;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        ll ans = 0; 
        for(int i=0;i<N && 2*nums[i] <= target;i++){
            ll minm = nums[i],maxAllowed = target - nums[i];
            ll idxMaxAllowed = upper_bound(nums.begin(), nums.end(), maxAllowed) - nums.begin() - 1;
            ans += getPower(2, idxMaxAllowed - i);
            ans %= MOD;
        }
        return ans;
    }
};