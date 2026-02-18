class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = (n & 1) ^ 1;
        while(n){
            int curr = n & 1;
            if((prev ^ curr) == 0){
                return false;
            }
            prev = curr;
            n >>= 1;
        }
        return true;
    }
};