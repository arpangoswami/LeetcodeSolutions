class Solution {
    constexpr static int dx[4] = {-1,0,0,1};
    constexpr static int dy[4] = {0,-1,1,0};
    bool isSafe(int x,int y,int rows,int cols,vector<vector<int>> &grid,vector<vector<bool>> &visited){
        return (x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] != 0 && !visited[x][y]);
    }
    long long dfs(int x,int y,vector<vector<int>> &grid,vector<vector<bool>> &visited,const int &rows, const int &cols){
        long long ans = grid[x][y];
        visited[x][y] = true;
        for(int k=0;k<4;k++){
            int nx = x+dx[k],ny = y+dy[k];
            if(isSafe(nx, ny, rows, cols, grid, visited)){
                ans += dfs(nx, ny, grid, visited, rows, cols);
            }
        }
        return ans;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] != 0 && !visited[i][j]){
                    long long num = dfs(i,j,grid,visited,rows,cols);
                    if((num % k) == 0 && num != 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};