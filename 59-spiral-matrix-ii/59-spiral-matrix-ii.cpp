class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ansMat(n,vector<int>(n));
        if(n & 1){
            ansMat[n/2][n/2] = n*n;
        }
        int val = 1;
        int tr = 0,br = n-1,rc = n-1,lc = 0;
        while(tr < br && lc < rc){
            for(int j=lc;j<rc;j++){
                ansMat[tr][j] = val++;
            }
            for(int i=tr;i<br;i++){
                ansMat[i][rc] = val++;
            }
            for(int j=rc;j>lc;j--){
                ansMat[br][j] = val++;
            }
            for(int i=br;i>tr;i--){
                ansMat[i][lc] = val++;
            }
            tr++;
            br--;
            rc--;
            lc++;
        }
        return ansMat;
    }
};