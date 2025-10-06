class Solution {
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    bool isSafe(int x,int y,int fx,int fy,int maxL,vector<vector<bool>> &visited,vector<vector<int>> &grid){
        return ((x >= 0) && (y >= 0) && (x <= fy) && (y <= fy) && grid[x][y] <= maxL && !visited[x][y]);
    }
    bool dfsReach(int x,int y,int fx,int fy,int maxL,vector<vector<bool>> &visited,vector<vector<int>> &grid){
        visited[x][y] = true;
        if(x == fx && y == fy){
            return true;
        }
        for(int k=0;k<4;k++){
            if(isSafe(x+dx[k],y+dy[k],fx,fy,maxL,visited,grid)){
                bool f = dfsReach(x+dx[k],y+dy[k],fx,fy,maxL,visited,grid);
                if(f){
                    return true;
                }
            }
        }
        return false;
    }
    bool canReach(vector<vector<int>> &grid,int maxL){
        int n = grid.size();
        if(grid[0][0] > maxL){
            return false;
        }
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        return dfsReach(0,0,n-1,n-1,maxL,visited,grid);
    }
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        int low = 0,n = grid.size(),high = n*n-1,ans = high;
        while(low <= high){
            int mid = (low + high)/2;
            if(canReach(grid,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};