class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum < 1 || sum > (9*num)){
            return "";
        }
        string ans;
        while(sum > 0 && num > 0){
            if(sum > 9){
                sum -= 9;
                ans.push_back('9');
            }else{
                ans.push_back('0' + sum);
                sum = 0;
            }
            num--;
        }
        while(num >0){
            ans.push_back('0');
            num--;
        }
        return ans;
    }
};