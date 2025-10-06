typedef pair<int,int> pii;
class Solution {
    int m;
    int n;
    int dx[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    bool isSafe(int i,int j,vector<vector<bool>> &visited){
        return ((i >= 0) && (j >= 0) && (i < m) && (j < n) && !visited[i][j]);
    }
    void dfs(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &matrix){
        visited[i][j] = true;
        for(int k=0;k<4;k++){
            int r = i + dx[k][0],c = j+dx[k][1];
            if(isSafe(r,c,visited) && matrix[r][c] >= matrix[i][j]){
                dfs(r,c,visited,matrix);
            }
        }
    }
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(i,0,pacific,matrix);
            dfs(i,n-1,atlantic,matrix);
            
        }
        for(int j=0;j<n;j++){
            dfs(0,j,pacific,matrix);
            dfs(m-1,j,atlantic,matrix);
        }
        // bfs(pac,pacific,matrix);
        // bfs(atl,atlantic,matrix);
        vector<vector<int>> sol;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    sol.push_back({i,j});
                }
            }
        }
        return sol;
    }
};