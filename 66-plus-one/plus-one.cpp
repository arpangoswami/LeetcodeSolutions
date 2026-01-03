class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0){
            return digits;
        }
        int n = digits.size();
        if(digits[n-1]!=9){
            digits[n-1]++;
            return digits;
        }else{
            int carry = 1;
            digits[n-1] = 0;
            for(int i=n-2;i>=0 && carry;i--){ 
                digits[i] = (digits[i] + 1)%10;
                if(digits[i] == 0){
                    carry = 1;
                }else{
                    carry = 0;
                }
            }
            if(carry){
                digits.insert(digits.begin(),1);
            }
            return digits;
        }
    }
};