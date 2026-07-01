class Solution {
    constexpr static int dx[4] = {-1,0,0,1};
    constexpr static int dy[4] = {0,-1,1,0};
    bool isSafe(int x,int y,vector<vector<bool>> &visited,int rows,int cols){
        return ((x >= 0) && (x < rows) && (y >= 0) && (y < cols) && !visited[x][y]);
    }
    void bfs(vector<vector<int>> &dist, queue<pair<int,int>> &thieves, vector<vector<bool>> &visited){
        int rows = dist.size(), cols = dist[0].size();
        while(!thieves.empty()){
            int x = thieves.front().first, y = thieves.front().second;
            thieves.pop();
            for(int k=0;k<4;k++){
                if(isSafe(x+dx[k],y+dy[k],visited,rows,cols)){
                    dist[x+dx[k]][y+dy[k]] = 1 + dist[x][y];
                    visited[x+dx[k]][y+dy[k]] = true;
                    thieves.push({x+dx[k], y+dy[k]});
                }
            }
        }
    }
    bool isSafeDFS(int x, int y, int minDist, vector<vector<int>> &dist,const int &rows,const int &cols, vector<vector<bool>> &visited){
        visited[x][y] = true;
        if(dist[x][y] < minDist){
            return false;
        }
        if((x == rows - 1) && (y == cols - 1)){
            return true;
        }
        bool ans = false;
        for(int k=0;k<4;k++){
            if(isSafe(x+dx[k], y+dy[k], visited, rows, cols)){
                ans = ans || isSafeDFS(x+dx[k], y+dy[k], minDist, dist, rows, cols, visited);
            }
        }
        return ans;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        queue<pair<int,int>> thieves;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]){
                    thieves.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        vector<vector<int>> dist(rows, vector<int> (cols));
        bfs(dist,thieves, visited);
        int ans = 0,low = 0,high = rows+cols;
        while(low <= high){
            int mid = (low + high)/2;
            vector<vector<bool>> visited(rows, vector<bool>(cols));
            if(isSafeDFS(0, 0, mid, dist, rows, cols, visited)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};