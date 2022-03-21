class Solution {
    int getFirstCharacter(string &s,char c){
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == c){
                return i;
            }
        }
        return -1;
    }
    int getLastCharacter(string &s,char c){
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i] == c){
                return i;
            }
        }
        return -1;
    }
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> last(26);
        for(char c='a';c<='z';c++){
            last[c-'a'] = getLastCharacter(s,c);
        }
        int n = s.size();
        for(int i=0;i<n;){
            int end = last[s[i]-'a'];
            int start = i;
            for(int j=start;j<=end;j++){
                end = max(end,last[s[j]-'a']);
            }
            ans.push_back(end-start+1);
            i = end+1;
        }
        return ans;
    }
};