class Solution {
    int dp[201][201];
    int recDp(int i,int j,vector<vector<int>> &matrix){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};
        int ans = 1;
        auto isSafe = [&](int x,int y){
            return ((x >= 0) && (y >= 0) && (x < matrix.size()) && (y < matrix[0].size()) && matrix[x][y] > matrix[i][j]);  
        };
        for(int k=0;k<4;k++){
            if(isSafe(i+dx[k],j+dy[k])){
                ans = max(ans,1+recDp(i+dx[k],j+dy[k],matrix));
            }
        }
        return dp[i][j] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = -1;
            }
        }
        int ans = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] == -1){
                    ans = max(ans,recDp(i,j,matrix));
                }
            }
        }
        return ans;
    }
};