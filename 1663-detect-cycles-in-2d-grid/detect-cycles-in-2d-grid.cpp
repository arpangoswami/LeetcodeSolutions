class Solution {
    constexpr static int dx[4] = {-1,0,0,1};
    constexpr static int dy[4] = {0,-1,1,0};
    bool isSafe(int newX,int newY,char &ch,vector<vector<char>> &grid,const int &rows, const int &cols){
        return (newX >= 0 && newY >= 0 && newX < rows && newY < cols && grid[newX][newY] == ch);
    }
    bool dfs(int x,int y, int parX, int parY, char ch,vector<vector<char>> &grid,vector<vector<bool>> &visited, const int &rows, const int &cols){
        visited[x][y] = true;
        for(int dir=0;dir<4;dir++){
            int nx = x+dx[dir], ny = y+dy[dir];
            if(isSafe(nx, ny, ch, grid, rows, cols)){
                if(visited[nx][ny]){
                    if(nx == parX && ny == parY){
                        continue;
                    }
                    return true;
                }else if(dfs(nx,ny,x,y,ch,grid,visited,rows,cols)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j]){
                    if(dfs(i,j,-1,-1,grid[i][j],grid,visited,rows,cols)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};