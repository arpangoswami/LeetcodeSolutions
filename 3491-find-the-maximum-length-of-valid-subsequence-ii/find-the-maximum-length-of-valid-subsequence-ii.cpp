class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 2;
        for(int mod = 0;mod < k; mod++){
            vector<int> dp(k, 0);
            for(int &num:nums){
                // mod represents the pairwise sum
                // modValue represents the 1st val
                // inverseVal represents (modValue + inverseVal) % k = mod
                int modValue = num % k;
                int inverseVal = (mod - modValue + k) % k;
                dp[modValue] = dp[inverseVal] + 1;
            }
            for (int val : dp) {
                ans = max(ans, val);
            }
        }
        return ans;
    }
};