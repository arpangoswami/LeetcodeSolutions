typedef long long ll;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0){
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(n == 0){
            return 0;
        }
        vector<vector<ll>> dp(m,vector<ll>(n,0));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        dp[m-1][n-1] = 1;
        for(int j=n-2;j>=0;j--){
            dp[m-1][j] = (obstacleGrid[m-1][j] ? 0 : dp[m-1][j+1]);
        }
        for(int i=m-2;i>=0;i--){
            dp[i][n-1] = (obstacleGrid[i][n-1] ? 0 : dp[i+1][n-1]);
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j] = (obstacleGrid[i][j] ? 0 : (ll)dp[i+1][j] + (ll)dp[i][j+1]);
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[0][0];
    }
};