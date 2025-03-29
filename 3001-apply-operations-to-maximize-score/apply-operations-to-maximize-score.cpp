using ll = long long;
class Solution {
    const ll MOD = 1e9+7;
    ll getDistinctPrimes(ll n){
        ll ans = 0;
        bool divBy2 = false;
        if(n % 2 == 0){
            divBy2 = true;
        }
        if(divBy2){
            ans++;
            while(n % 2 == 0){
                n /= 2;
            }
        }
        for(int i=3;i*i<=n;i+=2){
            if(n % i == 0){
                ans++;
                while(n % i == 0){
                    n /= i;
                }
            }
        }
        if(n > 1){
            ans++;
        }
        return ans;
    }
    ll getModSum(ll a,ll b){
        if(b == 0){
            return 1LL;
        }
        ll midProd = getModSum(a, b/2);
        ll eveSum = ((ll)midProd * (ll)midProd)%MOD;
        if(b % 2 == 0){
            return eveSum % MOD;
        }
        eveSum *= (ll)a;
        eveSum %= MOD;
        return eveSum;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> primeScores(n);
        for(int i=0;i<n;i++){
            primeScores[i] = getDistinctPrimes(nums[i]);
        }
        vector<ll> left(n),right(n);
        stack<ll> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && primeScores[i] > primeScores[st.top()]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }else{
                left[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && primeScores[i] >= primeScores[st.top()]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n;
            }else{
                right[i] = st.top();
            }
            st.push(i);
        }
        vector<array<ll,2>> ar(n);
        for(int i=0;i<n;i++){
            ar[i] = {nums[i], i};
        }
        sort(ar.begin(), ar.end(), greater<array<ll,2>>());
        ll ans = 1;
        for(int i=0;i<n && k > 0;i++){
            int idx = ar[i][1];
            ll subMath = (ll)(idx - left[idx])*(ll)(right[idx] - idx);
            ll sub = min(subMath, (ll)k);
            ll mul = getModSum(ar[i][0], sub);
            ans *= mul;
            ans %= MOD;
            k -= sub;
        }
        return (int)ans;
    }
};