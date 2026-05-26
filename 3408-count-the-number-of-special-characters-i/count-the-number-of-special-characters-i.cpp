class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> upper(26), lower(26);
        for(char &ch:word){
            if(isupper(ch)){
                upper[ch - 'A']++;
            }else{
                lower[ch - 'a']++;
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(upper[i] && lower[i]){
                ans++;
            }
        }
        return ans;
    }
};