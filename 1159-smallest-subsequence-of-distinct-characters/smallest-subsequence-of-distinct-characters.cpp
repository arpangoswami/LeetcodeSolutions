class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        if(n == 0){
            return "";
        }
        vector<int> lastPosition(26, -1);
        for(int i=0;i<n;i++){
            lastPosition[s[i] - 'a'] = i;
        }
        string ans;
        vector<bool> seen(26);
        ans.push_back(s[0]);
        seen[s[0] - 'a'] = true;
        for(int i=1;i<n;i++){
            while(!ans.empty() && s[i] < ans.back() && lastPosition[ans.back() - 'a'] > i && !seen[s[i] - 'a']){
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            if(!seen[s[i] - 'a']){
                seen[s[i] - 'a'] = true;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};