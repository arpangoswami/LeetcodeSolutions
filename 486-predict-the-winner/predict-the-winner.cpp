class Solution {
public:
    bool predictTheWinner(vector<int>& piles) {
        int n = piles.size();
        vector<int> pref(n);
        pref[0] = piles[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + piles[i];
        }
        function<int(int,int)> getSum = [&](int start, int end) -> int {
            return pref[end] - ((start == 0) ? 0 : pref[start - 1]);
        };
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i=0;i<n;i++){
            dp[i][i] = piles[i];
        }
        for(int i=0;i<(n-1);i++){
            dp[i][i+1] = max(piles[i], piles[i+1]);
        }
        for(int len=3;len<=n;len++){
            int lastStart = n - len;
            for(int start=0;start<=lastStart;start++){
                int end = start + len - 1;
                int sumSegment1 = getSum(start+1, end);
                int sumSegment2 = getSum(start, end-1);
                dp[start][end] = max(sumSegment1 - dp[start+1][end] + piles[start], piles[end] + sumSegment2 - dp[start][end-1]);
            }
        }
        return dp[0][n-1] >= (pref.back() - dp[0][n-1]);
    }
};