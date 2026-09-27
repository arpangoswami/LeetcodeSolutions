class Solution {
public:
    string reverseParentheses(string s) {
        unordered_map<int,int> brackets;
        stack<int> opening;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                opening.push(i);
            }else if(s[i] == ')'){
                int idx = opening.top();
                opening.pop();
                brackets[i] = idx;
                brackets[idx] = i;
            }
        }
        string ans;
        for(int i=0,d=1;i<n;i+=d){
            if(s[i] == '(' || s[i] == ')'){
                i = brackets[i];
                d = -d;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};