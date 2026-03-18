class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = (grid[0][0] <= k) ? 1 : 0;
        for(int i=1;i<rows;i++){
            grid[i][0] += grid[i-1][0];
            ans += (grid[i][0] <= k);
        }
        for(int j=1;j<cols;j++){
            grid[0][j] += grid[0][j-1];
            ans += (grid[0][j] <= k);
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                grid[i][j] += (grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]);
                ans += (grid[i][j] <= k);
            }
        }
        return ans;
    }
};