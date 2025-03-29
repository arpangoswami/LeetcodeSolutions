class Solution {
    const int MOD = 1e9+7;
    int getDistinctPrimes(int n){
        int ans = 0;
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
    int getModSum(int a,int b){
        if(b == 0){
            return 1;
        }
        int midProd = getModSum(a, b/2);
        long long eveSum = ((long long)midProd * (long long)midProd)%MOD;
        if(b % 2 == 0){
            return (int)(eveSum % MOD);
        }
        eveSum *= (long long)a;
        eveSum %= MOD;
        return (int)eveSum;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n);
        for(int i=0;i<n;i++){
            primeScores[i] = getDistinctPrimes(nums[i]);
        }
        vector<int> left(n),right(n);
        stack<int> st;
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
        vector<array<int,2>> ar(n);
        for(int i=0;i<n;i++){
            ar[i] = {nums[i], i};
        }
        sort(ar.begin(), ar.end(), greater<array<int,2>>());
        long long ans = 1;
        for(int i=0;i<n && k > 0;i++){
            int idx = ar[i][1];
            long long subMath = (long long)(idx - left[idx])*(long long)(right[idx] - idx);
            long long sub = min(subMath, (long long)k);
            long long mul = getModSum(ar[i][0], sub);
            ans *= mul;
            ans %= MOD;
            k -= sub;
        }
        return (int)ans;
    }
};