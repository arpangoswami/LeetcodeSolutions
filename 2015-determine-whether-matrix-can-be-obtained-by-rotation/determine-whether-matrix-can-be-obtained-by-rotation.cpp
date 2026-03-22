class Solution {
    vector<vector<int>> rotate(vector<vector<int>> &matrix){
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n - i - 1] = matrix[i][j];
            }
        }
        return ans;
    }
    bool checkEqual(vector<vector<int>> &matrix, vector<vector<int>> &matrix2){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] != matrix2[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
       vector<vector<int>> rotatedMat = rotate(mat);
       vector<vector<int>> rotatedMat2 = rotate(rotatedMat);
       vector<vector<int>> rotatedMat3 = rotate(rotatedMat2);
       return checkEqual(mat, target) || checkEqual(rotatedMat, target) || checkEqual(rotatedMat2, target) || checkEqual(rotatedMat3, target);
    }
};