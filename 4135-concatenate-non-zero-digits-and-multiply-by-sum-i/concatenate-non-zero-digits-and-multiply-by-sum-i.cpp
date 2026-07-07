class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = 0,sum = 0;
        while(n > 0){
            int rem = n%10;
            if(rem != 0){
                num = num * 10 + rem;
            }
            sum += rem;
            n /= 10;
        }
        int temp = num, rev = 0;
        while(temp > 0){
            rev *= 10;
            int rem = temp % 10;
            rev += rem;
            temp /= 10;
        }
        return ((long long)rev * (long long)sum);
    }
};