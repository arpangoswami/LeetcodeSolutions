class Solution {
public:
    int countCommas(int n) {
        return (n >= 1000) ? (n - 999) : 0;
    }
};