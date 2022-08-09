class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        
        unordered_map<int, int> mp;
        
        for (int i = 0; i < A.size(); ++i) {
            mp[A[i]] = i;
        }
        
        vector<long> dp(A.size(), 1);
        
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0 && mp.find(A[i] / A[j]) != mp.end()) {
                    dp[i] += (dp[j] * dp[mp[A[i] / A[j]]]) % 1000000007;
                }
            }
        }
        
        int ans = 0;
        for (auto cnt : dp) {
            ans = (ans + cnt) % 1000000007;
        }
        
        return ans;
    }
};