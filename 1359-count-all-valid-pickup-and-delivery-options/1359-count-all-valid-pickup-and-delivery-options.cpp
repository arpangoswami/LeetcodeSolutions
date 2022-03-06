typedef long long ll;
class Solution {
public:
    int countOrders(int n) {
        const ll MOD = 1e9+7;
        ll ans = 1LL;
        for(int i=1;i<=n;i++){
            ans *= i;
            ans %= MOD;
            ans *= (2*i-1);
            ans %= MOD;
        }
        return ans;
    }
};