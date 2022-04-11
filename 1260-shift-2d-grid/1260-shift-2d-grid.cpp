class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        if(m == 0){
            return {};
        }
        int n = grid[0].size(),total = m*n;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int currVal = i*n+j;
                int newVal = (currVal+k)%total;
                int row = newVal/n,col = newVal%n;
                ans[row][col] = grid[i][j];
            }
        }
        return ans;
    }
};