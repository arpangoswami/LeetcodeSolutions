class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int tillNow = 0;
        string ans;
        for(char c:s){
            if(c == '('){
                ans.push_back('(');
                tillNow++;
            }else if(c == ')'){
                if(tillNow > 0){
                    ans.push_back(')');
                    tillNow--;
                }
            }else{
                ans.push_back(c);
            }
        }
        if(tillNow > 0){
            string newAns;
            int N = ans.size();
            for(int i=N-1;i>=0;i--){
                if(tillNow > 0 && ans[i] == '('){
                    tillNow--;
                }else{
                    newAns.push_back(ans[i]);
                }
            }
            reverse(newAns.begin(),newAns.end());
            return newAns;
        }
        return ans;
    }
};