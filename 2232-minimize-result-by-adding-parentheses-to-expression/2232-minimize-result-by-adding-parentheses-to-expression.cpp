class Solution {
    int evaluate(string possible,int leftBracket,int rightBracket,int plusIdx){
        int left = 1,right = 1;
        if(leftBracket != 0){
            left = 0;
            for(int i=0;i<leftBracket;i++){
                left = (left*10+(possible[i]-'0'));
            }
        }
        if(rightBracket != (int)possible.size()-1){
            right = 0;
            for(int i=rightBracket+1;i<possible.size();i++){
                right = (right*10+(possible[i]-'0'));
            }
        }
        int val1 = 0,val2 = 0;
        for(int i=leftBracket+1;i<plusIdx;i++){
            val1 = val1*10+(possible[i]-'0');
        }
        for(int i=plusIdx+1;i<rightBracket;i++){
            val2 = val2*10+(possible[i]-'0');
        }
        return left*(val1+val2)*right;
    }
public:
    string minimizeResult(string expression) {
        int N = expression.size();
        int plusIdx = -1;
        for(int i=0;i<N;i++){
            if(expression[i] == '+'){
                plusIdx = i;
                break;
            }
        }
        string ans = "(";
        ans += expression;
        ans += ")";
        int val = evaluate(ans,0,(int)ans.size()-1,plusIdx+1);
        for(int i=0;i<=(plusIdx-1);i++){
            for(int j=plusIdx+1;j<N;j++){
                string firstPart = expression.substr(0,i);
                firstPart.push_back('(');
                string secondPart = expression.substr(i,j-i+1);
                secondPart.push_back(')');
                string thirdPart = expression.substr(j+1);
                string possible = firstPart+secondPart+thirdPart;
                int value = evaluate(possible,i,j+2,plusIdx+1);
                if(value < val){
                    ans = possible;
                    val = value;
                }
            }
        }
        return ans;
    }
};