class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<=60;i++){
            long long num = num1 - static_cast<long long>(i)*num2;
            if(num < i){
                return -1;
            }
            if(__builtin_popcountll(num) <= i){
                return i;
            }
        }
        return -1;

    }
};