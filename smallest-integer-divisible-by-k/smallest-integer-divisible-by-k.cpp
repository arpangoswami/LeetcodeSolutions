class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0){
            return -1;
        }
        int rem = 1;
        for(int i=0;i<k;i++){
            if(rem % k == 0){
                return (1+i);
            }
            rem = rem*10 + 1;
            rem %= k;
        }
        return -1;
    }
};