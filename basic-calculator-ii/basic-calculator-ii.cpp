class Solution {
public:
    int calculate(string s) {
        istringstream iss("+"+s+"+");
        char ch;
        int ans = 0,leftNum = 0,rightNum = 0;
        while(iss >> ch){
            if(ch == '+' || ch == '-'){
                ans += leftNum;
                iss >> leftNum;
                if(ch == '-'){
                    leftNum *= -1;
                }
            }else{
                iss >> rightNum;
                if(ch == '/'){
                    leftNum /= rightNum;
                }else{
                    leftNum *= rightNum;
                }
            }
        }
        return ans;
    }
};