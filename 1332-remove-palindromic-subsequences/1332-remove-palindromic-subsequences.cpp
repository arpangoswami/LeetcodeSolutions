class Solution {
public:
    bool isPali(string &s){
        int i=0,j = s.size()-1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.empty()){
            return 0;
        }
        if(isPali(s)){
            return 1;
        }
        return 2;
    }
};