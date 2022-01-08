class Solution {
public:
    int dp[71][71][71];
    int m,n;
    int solve(vector<vector<int>> &grid,int i,int j,int k){
        if(i == m){
            return 0;
        }
        if(j < 0 || j >= n || k < 0 || k >= n){
            return -1e9;
        }
        if(dp[i][j][k] != -1 || dp[i][k][j] != -1)
            return dp[i][j][k];
        return dp[i][j][k] = dp[i][k][j] = grid[i][j] + (j == k ? 0 : grid[i][k]) + max({solve(grid,i+1,j-1,k-1),solve(grid,i+1,j-1,k),solve(grid,i+1,j-1,k+1),solve(grid,i+1,j,k-1),solve(grid,i+1,j,k),solve(grid,i+1,j,k+1),solve(grid,i+1,j+1,k-1),solve(grid,i+1,j+1,k),solve(grid,i+1,j+1,k+1)});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        if(m == 0){
            return 0;
        }
        n = grid[0].size();
        if(n == 0){
            return 0;
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(grid,0,0,n-1);
    }
};