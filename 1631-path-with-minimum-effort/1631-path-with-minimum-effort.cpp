class Solution {
    const int dx[4] = {-1,0,0,1};
    const int dy[4] = {0,-1,1,0};
    bool isSafe(int x,int y,int prevX,int prevY,int maxDiff,vector<vector<bool>> &visited,vector<vector<int>> &heights){
        int m = heights.size(),n = heights[0].size();
        return ((x >= 0) && (y >= 0) && (x < m) && (y < n) && (abs(heights[x][y] - heights[prevX][prevY]) <= maxDiff) && !visited[x][y]);
    }
    bool dfs(int x,int y,vector<vector<int>> &heights,vector<vector<bool>> &visited,int maxDiff){
        int m = heights.size(),n = heights[0].size();
        if(x == m-1 && y == n-1){
            return true;
        }
        visited[x][y] = true;
        for(int k=0;k<4;k++){
            int nx = x+dx[k],ny = y+dy[k];
            if(isSafe(nx,ny,x,y,maxDiff,visited,heights) && dfs(nx,ny,heights,visited,maxDiff)){
                return true;
            }
        }
        return false;
    }
    bool check(vector<vector<int>> &heights,int maxDiff){
        int m = heights.size(),n = heights[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return dfs(0,0,heights,visited,maxDiff);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int maxm = INT_MIN,minm = INT_MAX;
        for(vector<int> &v:heights){
            maxm = max(*max_element(v.begin(),v.end()),maxm);
            minm = min(*min_element(v.begin(),v.end()),minm);
        }
        int low = 0LL,high = maxm - minm,ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(heights,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};