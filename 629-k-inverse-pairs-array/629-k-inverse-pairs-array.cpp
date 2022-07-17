class Solution {
    static constexpr int MOD = 1e9+7; 
    int recSolve(int n,int k,vector<vector<int>> &dp){
        if(n == 0){
            return 0;
        }else if(k == 0){
            return 1;
        }else if(dp[n][k] != -1){
            return dp[n][k];
        }
        int ans = recSolve(n-1,k,dp)+recSolve(n,k-1,dp);
        ans %= MOD;
        if((k-n)>=0){
            ans -= recSolve(n-1,k-n,dp);
            ans += MOD;
            ans %= MOD;
        }
        return dp[n][k] = ans;
    }
public:
    int kInversePairs(int n, int k) {
        if(n == 0){
            return 0;
        }else if(k == 0){
            return 1;
        }
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        int ans = recSolve(n,k,dp);
        if(k > 0){
            ans -= recSolve(n,k-1,dp);
            ans += MOD;
            ans %= MOD;
        }
        return ans;
    }
};

// public class Solution {
//     Integer[][] memo = new Integer[1001][1001];
//     int M = 1000000007;
//     public int kInversePairs(int n, int k) {
//         return ((inv(n, k) + M - (k > 0 ? inv(n, k - 1) : 0)) % M);
//     }
//     public int inv(int n, int k) {
//         if (n == 0)
//             return 0;
//         if (k == 0)
//             return 1;
//         if (memo[n][k] != null)
//             return memo[n][k];
//         int val = (inv(n - 1, k) + M - ((k - n) >= 0 ? inv(n - 1, k - n) : 0)) % M;
//         memo[n][k] = (inv(n, k - 1) + val) % M;
//         return memo[n][k];
//     }
// }