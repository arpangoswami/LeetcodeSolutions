class NumMatrix {
public:
    vector<vector<int>> prefSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        prefSum.resize(m);
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            prefSum[i].resize(n);
        }
        prefSum[0][0] = matrix[0][0];
        for(int i=1;i<n;i++){
            prefSum[0][i] = prefSum[0][i-1] + matrix[0][i];
        }
        for(int i=1;i<m;i++){
            prefSum[i][0] = prefSum[i-1][0] + matrix[i][0]; 
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                prefSum[i][j] = prefSum[i-1][j] + prefSum[i][j-1] + matrix[i][j] - prefSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int add1 = prefSum[row2][col2],add2 = (row1 == 0 || col1 == 0) ? 0 : prefSum[row1-1][col1-1];
        int sub1 = (row1 == 0) ? 0 : prefSum[row1-1][col2],sub2 = (col1 == 0) ? 0 : prefSum[row2][col1-1];
        return (add1 + add2 - sub1 - sub2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */