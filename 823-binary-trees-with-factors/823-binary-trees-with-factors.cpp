class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> st;
        for(int i=0;i<(int)arr.size();i++){
            st[arr[i]] = i;
        }
        int n = arr.size();
        const int MOD = 1e9+7;
        vector<long long> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i] % arr[j] == 0){
                    int div = arr[i]/arr[j];
                    if(st.count(div)){
                        int idx = st[div];
                        dp[i] += (dp[j]*dp[idx])%MOD;
                    }
                }
            }
        }
        long long ans = 0;
        for(long long &num:dp){
            ans += num;
            ans %= MOD;
        }
        return ans;
    }
};