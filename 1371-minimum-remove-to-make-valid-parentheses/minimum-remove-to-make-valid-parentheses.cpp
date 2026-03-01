class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int closeBracket = 0,openBracket = 0;
        for(char c:s){
            if(c == ')'){
                closeBracket++;
            }
        }
        string ans;
        for(char c:s){
            if(c == '('){
                if(openBracket < closeBracket){
                    openBracket++;
                    ans.push_back('(');
                }
            }else if(c == ')'){
                closeBracket--;
                if(openBracket > 0){
                    openBracket--;
                    ans.push_back(')');
                }
            }else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};