class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int rowIdx = 0, colIdx = cols - 1;
        int ans = 0;
        while(rowIdx < rows && colIdx >= 0){
            if(grid[rowIdx][colIdx] < 0){
                ans += (rows - rowIdx);
                colIdx--;
            }else{
                rowIdx++;
            }
        }
        return ans;
    }
};