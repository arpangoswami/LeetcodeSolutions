class Solution {
    array<vector<vector<int>>, 4> getPrefixMatrix(vector<vector<int>> &grid){
        int rows = grid.size(), cols = grid[0].size();
        if(rows == 0 || cols == 0){
            return {};
        }
        vector<vector<int>> rowMat(rows, vector<int>(cols));
        vector<vector<int>> colMat(rows, vector<int>(cols));
        vector<vector<int>> diagMat(rows, vector<int>(cols));
        vector<vector<int>> antidiagMat(rows, vector<int>(cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(j == 0){
                    rowMat[i][0] = grid[i][0];
                }else{
                    rowMat[i][j] = rowMat[i][j-1] + grid[i][j];
                }
            }
        }
        for(int j=0;j<cols;j++){
            for(int i=0;i<rows;i++){
                if(i == 0){
                    colMat[0][j] = grid[0][j];
                }else{
                    colMat[i][j] = colMat[i-1][j] + grid[i][j];
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i == 0 || j == 0){
                    diagMat[i][j] = grid[i][j];
                }else{
                    diagMat[i][j] = diagMat[i-1][j-1] + grid[i][j];
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=cols-1;j>=0;j--){
                if((i == 0) || (j == cols - 1)){
                    antidiagMat[i][j] = grid[i][j];
                }else{
                    antidiagMat[i][j] = grid[i][j] + antidiagMat[i-1][j+1];
                }
            }
        }
        return {rowMat, colMat, diagMat, antidiagMat};
    }
    int getDiagSum(int sx,int sy,int ex,int ey, vector<vector<int>> &diagMat){
        return diagMat[ex][ey] - ((sx == 0 || sy == 0) ? 0 : diagMat[sx-1][sy-1]);
    }
    int getAntiDiagSum(int sx,int sy,int ex,int ey, vector<vector<int>> &antidiagMat){
        int rows = antidiagMat.size(),cols = antidiagMat[0].size();
        return antidiagMat[ex][ey] - ((sx == 0 || sy == (cols-1)) ? 0 : antidiagMat[sx-1][sy+1]);
    }
    int getRowSum(int sx,int sy,int ex,int ey, vector<vector<int>> &rowMat) {
        return rowMat[ex][ey] - ((sy == 0) ? 0 : rowMat[sx][sy-1]);
    }
    int getColSum(int sx,int sy,int ex,int ey, vector<vector<int>> &colMat) {
        return colMat[ex][ey] - ((sx == 0) ? 0 : colMat[sx-1][sy]);
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        array<vector<vector<int>>,4> pref = getPrefixMatrix(grid);
        int rows = grid.size(), cols = grid[0].size();
        if(rows == 0 || cols == 0){
            return -1;
        }
        int maxLength = min(rows, cols);

        vector<vector<int>> rowMat = pref[0];
        vector<vector<int>> colMat = pref[1];
        vector<vector<int>> diagMat = pref[2];
        vector<vector<int>> antidiagMat = pref[3];
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         cout << antidiagMat[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        for(int length = maxLength;length >= 2; length--) {
            for(int i=0;i<=(rows - length);i++){
                for(int j=0;j<=(cols - length);j++){
                    
                    int desiredSum = getDiagSum(i,j,i+length-1,j+length-1,diagMat);
                    // if(i == 1 && j == 1 && length == 3){
                    //     cout << "diagSum: " << desiredSum << '\n';   
                    // }
                    if(getAntiDiagSum(i,j+length-1,i+length-1,j,antidiagMat) != desiredSum){
                        // if(i == 1 && j == 1 && length == 3){
                        //     cout << "antiDiagSum: " << getAntiDiagSum(i,j+length-1,i+length-1,j,antidiagMat) << '\n';   
                        // }
                        continue;
                    }
                    bool flag = true;
                    for(int k=i;k<=(i+length-1);k++){
                        if(getRowSum(k,j,k,j+length-1,rowMat) != desiredSum){
                            flag = false;
                            // if(i == 1 && j == 1 && length == 3){
                            //     cout << "rowSum: " << getRowSum(k,j,k,j+length-1,rowMat) << '\n';   
                            // }
                            break;
                        }
                    }
                    if(!flag){
                        continue;
                    }
                    for(int k=j;k<=(j+length-1);k++){
                        if(getColSum(i,k,i+length-1,k, colMat) != desiredSum){
                            flag = false;
                            // if(i == 1 && j == 1 && length == 3){
                            //     cout << "colSum: " << getColSum(i,k,i+length-1,k, colMat) << '\n';   
                            // }
                            break;
                        }
                    }
                    if(flag){
                        return length;
                    }
                }
            }
        }
        return 1;
    }
};