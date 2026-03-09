int dp[201][201][201][2];
class Solution {
    constexpr static int MOD = 1e9 + 7;
    int recDp(int zeroes,int ones, int consecutive, int lastVal, const int &limit){
        if(zeroes == 0 && ones == 0){
            return 1;
        }
        if(dp[zeroes][ones][consecutive][lastVal] != -1){
            return dp[zeroes][ones][consecutive][lastVal];
        }
        int &ans = dp[zeroes][ones][consecutive][lastVal] = 0;
        if(zeroes > 0){
            if(lastVal == 0 && (consecutive + 1) <= limit){
                ans += recDp(zeroes-1,ones,consecutive+1,0,limit);
                ans %= MOD;
            }else if(lastVal == 1){
                ans += recDp(zeroes-1,ones,1,0,limit);
                ans %= MOD;
            }
        }
        if(ones > 0){
            if(lastVal == 1 && (consecutive + 1) <= limit){
                ans += recDp(zeroes,ones-1,consecutive+1,1,limit);
                ans %= MOD;
            }else if(lastVal == 0){
                ans += recDp(zeroes,ones-1,1,1,limit);
                ans %= MOD;
            }
        }
        return ans;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        return (recDp(zero-1, one, 1, 0, limit) + recDp(zero, one-1, 1, 1, limit)) % MOD;
    }
};