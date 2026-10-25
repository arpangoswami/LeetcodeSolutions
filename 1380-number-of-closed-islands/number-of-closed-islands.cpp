class Solution {
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    bool isSafe(int x,int y,vector<vector<bool>> &visited,vector<vector<int>> &grid,int rows,int cols){
        return ((x >= 0) && (x < rows) && (y >= 0) && (y < cols) && !visited[x][y] && !grid[x][y]);
    }
    void dfs(int x,int y,vector<vector<bool>> &visited,vector<vector<int>> &grid,int rows,int cols){
        visited[x][y] = true;
        for(int k=0;k<4;k++){
            int nx = x+dx[k],ny = y+dy[k];
            if(isSafe(nx,ny,visited,grid,rows,cols)){
                dfs(nx,ny,visited,grid,rows,cols);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols));
        for(int i=0;i<rows;i++){
            if(grid[i][0] == 0 && !visited[i][0]){
                dfs(i,0,visited,grid,rows,cols);
            }
            if(grid[i][cols-1] == 0 && !visited[i][cols-1]){
                dfs(i,cols-1,visited,grid,rows,cols);
            }
        }
        for(int i=1;i<(cols-1);i++){
            if(grid[0][i] == 0 && !visited[0][i]){
                dfs(0,i,visited,grid,rows,cols);
            }
            if(grid[rows-1][i] == 0 && !visited[rows-1][i]){
                dfs(rows-1,i,visited,grid,rows,cols);
            }
        }
        int ans = 0;
        for(int i=1;i<(rows-1);i++){
            for(int j=1;j<(cols-1);j++){
                if(!grid[i][j] && !visited[i][j]){
                    ans++;
                    dfs(i,j,visited,grid,rows,cols);
                }
            }
        }
        return ans;
    }
};