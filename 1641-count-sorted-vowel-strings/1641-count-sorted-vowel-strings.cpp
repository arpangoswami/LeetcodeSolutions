class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int>(5,0));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=4;j++){
                for(int k=0;k<=j;k++){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        return dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4];
    }
};