class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        if(n == 0){
            return "";
        }
        vector<int> lastPosition(26);
        for(int i=0;i<n;i++){
            lastPosition[s[i]-'a'] = i;
        }
        vector<bool> seen(26);
        string ans;
        ans.push_back(s[0]);
        seen[ans[0] - 'a'] = true;
        for(int i=1;i<n;i++){
            while(ans.size() > 0 && s[i] < ans.back() && lastPosition[ans.back() - 'a'] > i && seen[s[i] - 'a'] == false){
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