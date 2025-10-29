class Solution {
public:
    int smallestNumber(int n) {
        int cnt = 0;
        while(n > 0){
            cnt++;
            n/=2;
        }
        return (1 << cnt) - 1;
    }
};