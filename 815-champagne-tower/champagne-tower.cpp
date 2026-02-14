class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> mat(102,vector<double>(102,0.00));
        mat[0][0] = (double)poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                double extra = (mat[i][j] - 1.0)/2.0;
                if(extra > 0){
                    mat[i+1][j] += extra;
                    mat[i+1][j+1] += extra;
                }
            }
        }
        return min(1.00,mat[query_row][query_glass]);
    }
};