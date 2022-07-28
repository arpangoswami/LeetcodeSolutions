class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> fre1(26),fre2(26);
        for(char c:s){
            fre1[c - 'a']++;
        }
        
        for(char c:t){
            fre2[c - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(fre1[i] != fre2[i]){
                return false;
            }
        }
        return true;
    }
};