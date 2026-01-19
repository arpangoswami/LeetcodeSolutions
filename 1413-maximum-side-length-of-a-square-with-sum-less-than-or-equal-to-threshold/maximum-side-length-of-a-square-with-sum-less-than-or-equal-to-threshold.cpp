class Solution {
    vector<vector<int>> getPrefixSum(vector<vector<int>> &mat){
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> prefMat(rows,vector<int>(cols));
        prefMat[0][0] = mat[0][0];
        for(int i=1;i<rows;i++){
            prefMat[i][0] = prefMat[i-1][0] + mat[i][0];
        }
        for(int i=1;i<cols;i++){
            prefMat[0][i] = prefMat[0][i-1] + mat[0][i];
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                prefMat[i][j] = mat[i][j] + prefMat[i-1][j] + prefMat[i][j-1] - prefMat[i-1][j-1];
            }
        }
        return prefMat;
    }
    int getSum(int sx, int sy, int ex, int ey, vector<vector<int>> &prefMat){
        int sum = prefMat[ex][ey];
        int rows = prefMat.size(),cols = prefMat[0].size();
        if(sy > 0){
            sum -= prefMat[ex][sy-1];
        }
        if(sx > 0){
            sum -= prefMat[sx-1][ey];
        }
        if(sx > 0 && sy > 0){
            sum += prefMat[sx-1][sy-1];
        }
        return sum;
    }
    bool check(int squareSize, int threshold, vector<vector<int>> &prefMat) {
        int rows = prefMat.size(), cols = prefMat[0].size();
        for(int i=0;i<=(rows-squareSize);i++){
            for(int j=0;j<=(cols-squareSize);j++){
                int sum = getSum(i,j,i+squareSize-1,j+squareSize-1,prefMat);
                if(sum <= threshold){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        if(rows == 0){
            return 0;
        }
        int cols = mat[0].size();
        if(cols == 0){
            return 0;
        }
        vector<vector<int>> prefMat = getPrefixSum(mat);
        int low = 1,high = min(rows,cols),ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(check(mid, threshold, prefMat)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};