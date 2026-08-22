class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n,sum = 0,product = 1;
        while(n > 0){
            int digit = n % 10;
            n /= 10;
            sum += digit;
            product *= digit;
        }
        return (original % (sum + product)) == 0;
    }
};