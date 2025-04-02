using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        vector<int> suffixMaximum(n),prefixMaximum(n);
        for(int i=n-2;i>=0;i--){
            suffixMaximum[i] = max(nums[i+1], suffixMaximum[i+1]);
        }
        for(int i=1;i<n;i++){
            prefixMaximum[i] = max(nums[i-1], prefixMaximum[i-1]);
        }
        for(int i=1;i<=(n-2);i++){
            ans = max(ans, (ll)(prefixMaximum[i] - nums[i])*(ll)suffixMaximum[i]);
        }
        return ans;
    }
};