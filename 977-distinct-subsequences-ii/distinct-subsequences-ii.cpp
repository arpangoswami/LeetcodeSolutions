typedef long long ll;
const ll mod = 1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<ll> dp(n+1);
        vector<int> prevAppeared(26,-1);
        dp[n] = 1L;
        for(int i=n-1;i>=0;i--){
            ll x = dp[i+1];
            ll y = 0;
            if(prevAppeared[s[i] - 97]!=-1){
                int idx = prevAppeared[s[i] - 97];
                y = dp[idx+1];
            }
            dp[i] = ((2*x - y)+mod)%mod;
            prevAppeared[s[i] - 97] = i;
        }
        return (int)(dp[0] - 1 + mod)%mod; 
    }
};