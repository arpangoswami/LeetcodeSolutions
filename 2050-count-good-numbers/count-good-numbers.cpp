using ll = long long;
class Solution {
    const ll MOD = 1e9 + 7;
    ll binExp(ll base, ll exp) {
        ll ans = 1L;
        ll mul = base;
        while(exp > 0){
            if(exp & 1){
                ans *= mul;
                ans %= MOD;
            }
            mul *= mul;
            mul %= MOD;
            exp >>= 1;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        ll even = (n+1)/2, odd = n/2;
        return static_cast<int>((binExp(5LL, even) * binExp(4LL, odd))%MOD);
    }
};