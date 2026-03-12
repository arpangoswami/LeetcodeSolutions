class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int justHighestPower = floor(log2(n)+1);
        int allOnes = (1 << justHighestPower) - 1;
        return allOnes ^ n;
    }
};