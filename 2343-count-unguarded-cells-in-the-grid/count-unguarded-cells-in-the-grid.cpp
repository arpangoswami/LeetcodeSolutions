class Solution {
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    bool isSafe(int x,int y,vector<vector<int>> &grid){
        return (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] < 2);
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        for(vector<int> &v:guards){
            grid[v[0]][v[1]] = 2;
        }
        for(vector<int> &v:walls){
            grid[v[0]][v[1]] = 3;
        }
        for(vector<int> &v:guards){
            for(int k=0;k<4;k++){
                int x = v[0]+dx[k],y = v[1]+dy[k];
                while(isSafe(x,y,grid)){
                    grid[x][y] = 1;
                    x += dx[k];
                    y += dy[k];
                }
            }
        }
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans += (grid[i][j] == 0);
            }
        }
        return ans;
    }
};