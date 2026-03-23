using ll = long long;
class Solution {
    constexpr static int MOD = 1e9 + 7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<ll>> dpMax(rows, vector<ll>(cols));
        vector<vector<ll>> dpMin(rows, vector<ll>(cols));

        dpMax[0][0] = dpMin[0][0] = grid[0][0];

        for(int j = 1; j < cols; j++) {
            ll prod = dpMax[0][j-1] * grid[0][j];
            dpMax[0][j] = dpMin[0][j] = prod;
        }
        for(int i = 1; i < rows; i++) {
            ll prod = dpMax[i-1][0] * grid[i][0];
            dpMax[i][0] = dpMin[i][0] = prod;
        }
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                ll leftMin = dpMin[i][j-1] * grid[i][j];
                ll leftMax = dpMax[i][j-1] * grid[i][j];
                ll upMin   = dpMin[i-1][j] * grid[i][j];
                ll upMax   = dpMax[i-1][j] * grid[i][j];
                dpMax[i][j] = max({leftMin, leftMax, upMin, upMax});
                dpMin[i][j] = min({leftMin, leftMax, upMin, upMax});
            }
        }

        ll result = dpMax[rows-1][cols-1];
        if(result < 0) return -1;
        return result % MOD;
    }
};