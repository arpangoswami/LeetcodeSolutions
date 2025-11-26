class Solution {
    constexpr static int MOD = 1e9 + 7;
    int recDp(int row,int col, int sum, const int k, vector<vector<int>> &grid,vector<vector<vector<int>>> &dp) {
        int m = grid.size(), n = grid[0].size();
        if(row >= m || col >= n) {
            return 0;
        }
        sum += grid[row][col];
        sum %= k;
        if(dp[row][col][sum] != -1) {
            return dp[row][col][sum];
        }
        if(row == m-1 && col == n-1 && sum == 0){
            return 1;
        }
        int ans = 0;
        ans += recDp(row+1, col, sum, k, grid, dp);
        ans %= MOD;
        ans += recDp(row, col+1, sum, k, grid, dp);
        ans %= MOD;
        return dp[row][col][sum] = ans;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows+1, vector<vector<int>> (cols + 1, vector<int>(k+1, - 1)));
        return recDp(0, 0, 0, k, grid, dp);
    }
};