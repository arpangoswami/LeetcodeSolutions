using ll = long long;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int totalSize = rows * cols;
        vector<ll> pref(totalSize);
        vector<ll> suff(totalSize);
        
        int MOD = 12345;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int idx = i*cols + j;
                ll left = (idx > 0) ? pref[idx-1] : 1;
                pref[idx] = (left * grid[i][j]) % MOD;
            }
        }
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                int idx = i*cols + j;
                ll right = (idx == (totalSize - 1)) ? 1 : suff[idx+1];
                suff[idx] = (right * grid[i][j])%MOD;
            }
        }
        vector<ll> prodSelf(totalSize);
        for(int i=0;i<(totalSize);i++){
            ll left = (i > 0) ? pref[i-1] : 1;
            ll right = (i < (totalSize - 1)) ? suff[i+1] : 1;
            prodSelf[i] = (left * right) % MOD;
        }
        vector<vector<int>> ans(rows, vector<int>(cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int idx = i*cols + j;
                ans[i][j] = prodSelf[idx];
            }
        }
        return ans;
    }
};