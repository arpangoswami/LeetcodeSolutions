class Solution {
    int lcs(string &word1,string &word2){
        int m = word1.size(),n = word2.size();
        vector<vector<int>> dp(2,vector<int>(n+1));
        int prevRow = 0,currRow = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[currRow][j] = dp[prevRow][j-1] + 1;
                }else{
                    dp[currRow][j] = max(dp[currRow][j-1],dp[prevRow][j]);
                }
            }
            prevRow ^= 1;
            currRow ^= 1;
        }
        return dp[prevRow][n];
    }
public:
    int minDistance(string word1, string word2) {
        int n = lcs(word1,word2);
        return (int)word1.size()+(int)word2.size() - 2*n;
    }
};