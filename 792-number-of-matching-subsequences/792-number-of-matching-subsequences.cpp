class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int  n = s.size();
        int dp[n+1][26];
        
        for(int i=0; i<26; ++i)
            dp[n][i] = n;
        
        for(int i=n-1; i>=0; --i){
            for(int j=0; j< 26; ++j)
                dp[i][j] = dp[i+1][j];
            dp[i][s[i]-'a'] = i;
        }
        
        int ans = 0;
        for(string s : words){
            int pos = 0;bool ok = 1;
            for(char ch : s){
                pos = dp[pos][ch-'a'];
                if(pos == n){
                    ok = 0;
                    break;
                }
                pos++;
            }
            if(ok) ++ans;
            
        }
        return ans;
                
        
    }
};