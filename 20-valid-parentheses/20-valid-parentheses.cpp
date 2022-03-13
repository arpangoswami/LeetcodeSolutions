class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        char c;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i] == '{' || s[i] == '['){
                parentheses.push(s[i]);
            }
            else{
                if(s[i] == ')'){
                    if(parentheses.empty())
                        return false;
                    else{
                        c = parentheses.top();
                        parentheses.pop();
                        if(c!='('){
                            return false;
                        }
                    }
                }
                else if(s[i] == '}'){
                    if(parentheses.empty())
                        return false;
                    else{
                        c = parentheses.top();
                        parentheses.pop();
                        if(c!='{'){
                            return false;
                        }
                    }
                }
                else if(s[i] == ']'){
                    if(parentheses.empty())
                        return false;
                    else{
                        c = parentheses.top();
                        parentheses.pop();
                        if(c!='['){
                            return false;
                        }
                    }
                }        
            }
        }
        if(!parentheses.empty()){
            return false;
        }
        return true;
    }
};