using ll = long long;
class Solution {
    constexpr static ll MOD = 1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        ll ans = 0; 
        ll left = 0,right = N-1;
        vector<ll> pow2(N);
        pow2[0] = 1l;
        for(int i=1;i<N;i++){
            pow2[i] = pow2[i-1] * 2L;
            pow2[i] %= MOD;
        }
        while(left <= right){
            ll sum = nums[left] + nums[right];
            if(sum > target){
                right--;
            }else{
                ans += pow2[right - left];
                ans %= MOD;
                left++;
            }
        }
        return ans;
    }
};