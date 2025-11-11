class Solution {
    int recSolve(int idx,int m,int n,vector<vector<vector<int>>> &dp, vector<pair<int,int>> &freq){
        if(idx >= freq.size()){
            return 0;
        }
        if(dp[idx][m][n] != -1){
            return dp[idx][m][n];
        }
        int &ans = dp[idx][m][n];
        ans = 0;
        if(freq[idx].first <= m && freq[idx].second <= n){
            ans = 1 + recSolve(idx+1, m - freq[idx].first, n - freq[idx].second, dp, freq);
        }
        ans = max(ans, recSolve(idx+1, m, n, dp, freq));
        return ans;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        sort(strs.begin(), strs.end(), [](string &s1, string &s2){
            return s1.size() < s2.size();
        });
        vector<pair<int,int>> freq(strs.size());
        for(int i=0;i<strs.size();i++){
            int oneFreq = count(strs[i].begin(),strs[i].end(),'1');
            int zeroFreq = strs[i].size() - oneFreq;
            freq[i] = {zeroFreq, oneFreq};
        }
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>> (m+1, vector<int>(n+1, -1)));
        return recSolve(0,m,n,dp,freq);
    }
};