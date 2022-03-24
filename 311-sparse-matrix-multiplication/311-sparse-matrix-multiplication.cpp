class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(),n = mat2[0].size(),p = mat2.size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<p;k++){
                    ans[i][j] += mat1[i][k]*mat2[k][j];
                }
            }
        }
        return ans;
    }
};