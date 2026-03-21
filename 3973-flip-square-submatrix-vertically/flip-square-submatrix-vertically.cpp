class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rows = grid.size(), cols = grid[0].size();
        int startX = x,lastX = x+k-1, midX = x + k/2 - 1;
        for(int i=startX,swapRow = lastX;i<=midX;i++,swapRow--){
            for(int j=y;j<=(y+k-1);j++){
                swap(grid[i][j], grid[swapRow][j]);
            }
        }
        return grid;
    }
};