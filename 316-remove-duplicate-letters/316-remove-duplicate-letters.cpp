class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, vector<int> > umap;
        vector<bool> valid(26, false);
        string res = "";

        for(int i=0; i<s.length(); i++){
            umap[s[i]].push_back(i);
            valid[s[i]-'a'] = true;
        }

        int distinctCount = umap.size();
        int curIndex = 0;

        while(distinctCount--){
            for(char ch='a'; ch<='z'; ch++) {
			    // check character validity smaller -> bigger
                if(valid[ch-'a']) {
                    bool flag = true;
                    int index = lower_bound(umap[ch].begin(), umap[ch].end(), \
                                            curIndex) - umap[ch].begin();
					// check if all remaining characters appear atleast once if current character is choosen
                    for(char ch2='a'; ch2<='z'; ch2++) { 
                        if(not valid[ch2-'a'] or ch == ch2)   continue;
                        if(upper_bound(umap[ch2].begin(), umap[ch2].end(), \
                                       umap[ch][index]) - umap[ch2].begin() == umap[ch2].size()) {
                            flag = false;
                            break;
                        }
                    }

                    if(flag) {
                        valid[ch-'a'] = false;
                        res += ch;
                        curIndex = umap[ch][index];
                        umap.erase(ch);
                        break;
                    }
                }
            }
        }
        return res;
    }
};