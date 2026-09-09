class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for (long long t = 1000; t <= 1000000000000000LL; t *= 1000)
            ans += max(0LL, n - (t - 1));
        return ans;
    }
};