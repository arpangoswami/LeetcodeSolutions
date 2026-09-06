class Solution {
public:
    int distinctSubsequence(int i,int j,string &s,string &t,int m,int n,int **dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j == n){
            return 1;
        }
        else if(i == m){
            return 0;
        }
        int ans = dp[i][j];
        if(s[i] != t[j]){
            ans = distinctSubsequence(i+1,j,s,t,m,n,dp);
        }
        else{
            ans = distinctSubsequence(i+1,j,s,t,m,n,dp) + distinctSubsequence(i+1,j+1,s,t,m,n,dp);
        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int m = s.size(),n = t.size();
        int **dp = new int*[m+1];
        for(int i=0;i<=m;i++){
            dp[i] = new int[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j] = -1;
            }
        }
        int ans = distinctSubsequence(0,0,s,t,m,n,dp);
        for(int i=0;i<=m;++i){
            delete []dp[i];
        }
        delete []dp;
        return ans;
    }
};