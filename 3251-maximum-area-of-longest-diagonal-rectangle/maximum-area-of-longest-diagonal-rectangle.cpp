class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0,ans = 0;
        for(vector<int> &v:dimensions) {
            int diag = v[0]*v[0] + v[1]*v[1];
            if(diag > maxDiag) {
                maxDiag = diag;
                ans = v[0]*v[1];
            }else if(diag == maxDiag){
                ans = max(ans, v[0]*v[1]);
            }
        }
        return ans;
    }
};