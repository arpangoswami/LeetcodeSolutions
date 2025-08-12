typedef long long ll;
class Solution {
    ll powerFn(int base,int exp){
        if(exp == 0){
            return 1;
        }
        ll smallAns = powerFn(base,exp/2);
        if(exp%2 == 0){
            return smallAns*smallAns;
        }
        return smallAns*smallAns*base;
    }
    constexpr static ll MOD = 1e9+7;
    ll recDp(ll num,ll n,ll x,vector<vector<ll>> &dp){
        //cout << "num: "<<num << " n: "<<n << '\n';
        if(n == 0){
            return 1LL;
        }
        if(powerFn(num,x) > n){
            return dp[num][n] = 0;
        }
        if(dp[num][n] != -1){
            return dp[num][n];
        }
        ll ans = 0;
        ans += recDp(num+1,n,x,dp);
        ans += recDp(num+1,n-powerFn(num,x),x,dp);
        ans %= MOD;
        //cout << "num: "<<num << " n: "<<n << " ans: " << ans << '\n';
        return dp[num][n] = ans;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<ll>> dp(n+10,vector<ll>(n+10,-1)); 
        return recDp(1,n,x,dp);
    }
};