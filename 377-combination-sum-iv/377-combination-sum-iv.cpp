class Solution {
    int recDp(vector<int> &nums,int target,vector<int> &dp){
        if(target < 0){
            return 0;
        }else if(target == 0){
            return 1;
        }else if(dp[target] != -1){
            return dp[target];
        }
        int &ans = dp[target];
        ans = 0;
        for(int &x:nums){
            if(x <= target){
                ans += recDp(nums,target-x,dp);
            }
        }
        return ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return recDp(nums,target,dp);
    }
};