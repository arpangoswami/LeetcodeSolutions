typedef long long ll;
class Solution {
    ll power(ll a, ll b){
        ll res=1;
        while(b>0){
            if(b&1){
                res=(res*a);
            }
            a=(a*a);
            b>>=1;
        }
        return res;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int N = s.size(),K = digits.size();
        vector<int> dp(N+1);
        dp[N] = 1;
        for(int i=N-1;i>=0;i--){
            int numPresent = s[i] - '0';
            for(string x:digits){
                int digitCheck = stoi(x);
                if(digitCheck < numPresent){
                    int choices = K,places = N-i-1;
                    dp[i] += power(choices,places);
                }else if(digitCheck == numPresent){
                    dp[i] += dp[i+1];
                }
            }
        }
        for(int i=1;i<N;i++){
            dp[0] += power(K,i);
        }
        return dp[0];
    }
};