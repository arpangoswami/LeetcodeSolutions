typedef array<int,3> ar;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        deque<ar> q;
        q.push_front({0,0,0});
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        visited[0][0] = true;
        auto isSafe = [&](int x,int y){
            return ((x >= 0) && (y >= 0) && (x < m) && (y < n) && !visited[x][y]);  
        };
        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};
        while(!q.empty()){
            int x = q.front()[0],y = q.front()[1],steps = q.front()[2];
            q.pop_front();
            if(x == m-1 && y == n-1){
                return steps;
            }
            for(int k=0;k<4;k++){
                int nx = x+dx[k],ny = y+dy[k];
                if(isSafe(nx,ny)){
                    if(grid[nx][ny] == 1){
                        q.push_back({nx,ny,steps+1});
                        visited[nx][ny] = true;
                    }else{
                        q.push_front({nx,ny,steps});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return -1;
    }
};