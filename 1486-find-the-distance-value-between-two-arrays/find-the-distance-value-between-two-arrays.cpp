class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        auto [min1, max1] = ranges::minmax(arr1);
        auto [min2, max2] = ranges::minmax(arr2);
        int lo = min(min1, min2) - d - 1;  // smallest value we look up
        vector<int> upto(max(max1, max2) + d - lo + 1);
        for (int b : arr2) ++upto[b - lo];
        partial_sum(upto.begin(), upto.end(), upto.begin());  // upto[v - lo]: how many b are <= v
        auto far = [&](int a) {  // no b in [a - d, a + d]
            return upto[a + d - lo] == upto[a - d - 1 - lo];
        };
        return ranges::count_if(arr1, far);
    }
};