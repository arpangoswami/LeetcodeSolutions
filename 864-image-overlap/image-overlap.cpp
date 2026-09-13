class Solution {
    public:
        int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
            int n = A.size();
            vector<pair<int,int>> a, b;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (A[i][j]) a.push_back({i, j});
                    if (B[i][j]) b.push_back({i, j});
                }
            unordered_map<int, int> cnt;
            int res = 0;
            for (auto& [i1, j1] : a)
                for (auto& [i2, j2] : b)
                    res = max(res, ++cnt[(i1 - i2 + n) * 64 + (j1 - j2 + n)]);
            return res;
        }
};