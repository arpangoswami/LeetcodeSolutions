class Solution {
    int recDp(int i,int j,int n,vector<vector<int>> &dp){
        if(i == n){
            return 1LL;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int &ans = dp[i][j];
        ans = 0;
        for(int k=j;k<=4;k++){
            ans += recDp(i+1,k,n,dp);
        }
        return ans;
    }
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        return recDp(0,0,n,dp);
    }
};