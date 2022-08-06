class Solution {
public:
    int poorPigs(int b, int m, int t) {
        return ceil(log(b)/log((t/m) + 1));
    }
};