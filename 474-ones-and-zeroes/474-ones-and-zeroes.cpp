class Solution {
public:
    int dp[601][101][101];
    vector<array<int,2>> freq;
    int solve(int i,vector<string> &strs,int m,int n){
        if(i < 0){
            return 0;
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int ans = solve(i-1,strs,m,n);
        if(freq[i][0] <= m && freq[i][1] <= n){
            ans = max(ans,1 + solve(i-1,strs,m-freq[i][0],n-freq[i][1]));
        }
        return dp[i][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        freq.resize(strs.size());
        for(int i=0;i<strs.size();i++){
            freq[i][0] = 0;
            freq[i][1] = 0;
            for(char c:strs[i]){
                freq[i][c - '0']++;
            }
        }
        for(int i=0;i<=strs.size();i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(strs.size()-1,strs,m,n);
    }
};