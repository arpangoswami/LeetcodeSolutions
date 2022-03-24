class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        if(n == 0){
            return "";
        }
        vector<int> lastSeen(26);
        for(int i=0;i<n;i++){
            lastSeen[s[i] - 'a'] = i;
        }
        vector<bool> seen(26);
        string ans;
        for(int i=0;i<n;i++){
            while(!seen[s[i] - 'a'] && ans.size() > 0 && s[i] < ans.back() && lastSeen[ans.back() - 'a'] > i){
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            if(!seen[s[i] - 'a']){
                ans.push_back(s[i]);
                seen[s[i] - 'a'] = true;
            }
        }
        return ans;
    }
};