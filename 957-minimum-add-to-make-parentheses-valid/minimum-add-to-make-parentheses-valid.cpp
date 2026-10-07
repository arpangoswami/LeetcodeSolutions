class Solution {
public:
    int minAddToMakeValid(string s) {
        int pref = 0, ans = 0;
        for(char ch:s){
            if(ch == '('){
                pref++;
            }else{
                pref--;
            }
            if(pref < 0){
                ans++;
                pref = 0;
            }
        }
        ans += pref;
        return ans;
    }
};