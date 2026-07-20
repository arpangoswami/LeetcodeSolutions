class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        if(rows == 0){
            return {};
        }
        int cols = grid[0].size();
        int total = rows*cols;
        k %= total;
        vector<vector<int>> ans(rows, vector<int> (cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int original = i*cols + j;
                int newPlace = (original + k)%total;
                int x = newPlace/cols;
                int y = newPlace%cols;
                ans[x][y] = grid[i][j];
            }
        }
        return ans;
    }
};