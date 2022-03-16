class Solution {
public:
    int max_length = 0;
    int solve(string &s,int idx,int n,vector<int> &dp,unordered_set<string> &dict){
        if(idx == n){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int len = min(n-idx,max_length);
        string word;
        int ptr = idx;
        for(int l = 1;l<=len;l++){
            word.push_back(s[ptr++]);
            if(dict.count(word)){
                int ans = solve(s,ptr,n,dp,dict);
                if(ans){
                    return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n,-1);
        unordered_set<string> dict;
        for(string x:wordDict){
            max_length = max(max_length,(int)x.size());
            dict.insert(x);
        }
        return solve(s,0,s.size(),dp,dict);
    }
};