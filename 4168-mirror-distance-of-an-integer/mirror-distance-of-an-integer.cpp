class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n, reversed = 0;
        while(temp){
            int add = temp % 10;
            reversed = reversed * 10 + add;
            temp /= 10;
        }
        return abs(reversed - n);
    }
};