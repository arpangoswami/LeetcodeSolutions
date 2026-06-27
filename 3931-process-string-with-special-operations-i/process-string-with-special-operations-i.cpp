class Solution {
public:
    string processStr(string s) {
        string ans;
        for(char &ch:s){
            if(ch == '#'){
                ans += ans;
            }else if(ch == '%'){
                reverse(ans.begin(), ans.end());
            }else if(ch == '*'){
                if (!ans.empty()) ans.pop_back();
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};