class Solution {
    int solve(vector<int> &nums,vector<vector<int>> &dp,int low,int high){
        if(low > high){
            return 0;
        }
        if(dp[low][high] != -1){
            return dp[low][high];
        }
        int ans = 0,n = nums.size();
        for(int i=low;i<=high;i++){
            int left = (low == 0) ? 1 : nums[low-1];
            int right = (high == n-1) ? 1 : nums[high+1];
            ans = max(ans,nums[i]*left*right + solve(nums,dp,low,i-1) + solve(nums,dp,i+1,high));
        }
        return dp[low][high] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,dp,0,n-1);
    }
};