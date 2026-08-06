class Solution {
    int digitPr(int num){
        int ans = 1;
        while(num){
            ans *= (num % 10);
            num /= 10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<(n+t);i++){
            if(digitPr(i) % t == 0){
                return i;
            }
        }
        return -1;
    }
};