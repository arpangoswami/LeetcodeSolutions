class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int output = 0;
        std::sort(points.begin(), points.end(), [](const std::vector<int> &x, const std::vector<int> &y) {
            if (x[0] != y[0]) return x[0] < y[0];
            return x[1] >= y[1];
        });
        size_t n = points.size();
        for (size_t i = 0; i < n; ++i) {
            long long lowerY = INT64_MIN;
            for (size_t j = i + 1; j < n; ++j) {
                if (points[i][1] < points[j][1]) continue;
                else if (points[j][1] <= lowerY) continue;
                lowerY = std::max(lowerY, static_cast<long long>(points[j][1]));
                ++output;
            }
        }
        return output;
    }
};