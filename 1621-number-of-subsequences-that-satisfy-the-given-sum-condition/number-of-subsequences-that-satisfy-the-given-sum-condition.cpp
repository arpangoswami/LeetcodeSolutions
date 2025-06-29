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
        ll left = 0,right = N-1;
        while(left <= right){
            ll sum = nums[left] + nums[right];
            if(sum > target){
                right--;
            }else{
                ans += getPower(2, right - left);
                ans %= MOD;
                left++;
            }
        }
        return ans;
    }
};