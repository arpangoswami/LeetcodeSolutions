class Solution {
public:
    int uniquePaths(int m, int n) {
        int **dp = new int *[m];
        for(int i=0;i<m;i++){
            dp[i] = new int[n]();
        }
        dp[m-1][n-1] = 1;
        for(int i=n-2;i>=0;i--){
            dp[m-1][i] = 1;
        }
        for(int i=m-2;i>=0;i--){
            dp[i][n-1] = 1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        int ans = dp[0][0];
        for(int i=0;i<m;i++){
            delete []dp[i];
        }
        delete []dp;
        return ans;
    }
};