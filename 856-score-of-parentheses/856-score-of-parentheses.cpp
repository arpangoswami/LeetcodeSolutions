class Solution {
public:
    int scoreOfParentheses(string S) {
        int mul = 1,ans = 0;
        for(int i=0;i<S.size();i++){
            if(S[i] == '('){
                if(S[i+1] == '('){
                    mul *= 2;
                }else{
                    ans += mul;
                    i++;
                }
            }else{
                mul /= 2;
            }
        }
        return ans;
    }
};