class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int secondLast = 0,last = 1;
        for(int i=2;i<=n;i++){
            int ans = (secondLast + last);
            secondLast = last;
            last = ans;
        }
        return last;
    }
};