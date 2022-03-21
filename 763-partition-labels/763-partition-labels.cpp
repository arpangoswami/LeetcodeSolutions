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
        vector<pair<int,int>> firstLast(26);
        for(char c='a';c<='z';c++){
            firstLast[c-'a'].first = getFirstCharacter(s,c);
            firstLast[c-'a'].second = getLastCharacter(s,c);
        }
        int n = s.size();
        for(int i=0;i<n;){
            int end = firstLast[s[i]-'a'].second;
            int start = i;
            for(int j=start;j<=end;j++){
                end = max(end,firstLast[s[j]-'a'].second);
            }
            ans.push_back(end-start+1);
            i = end+1;
        }
        return ans;
    }
};