class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        //upper - prefMax(+ve), lower - prefMin(-ve) -> min of these two
        //4, -3, 3. 6 - 4 = 2(Invalid). 3 + 3 = 6(Valid)
        long long n = differences.size(), pref = 0L, maxVal = 0L, minVal = 0L;
        for(int i=0;i<n;i++){
            pref += differences[i];
            maxVal = max(maxVal, pref);
            minVal = min(minVal, pref);
        }
        return max(0LL, (upper - maxVal) - (lower - minVal) + 1);
    }
};