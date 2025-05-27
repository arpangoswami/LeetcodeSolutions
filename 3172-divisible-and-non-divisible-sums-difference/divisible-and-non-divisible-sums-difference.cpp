class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divisibleNums = n/m, divisibleSum = (divisibleNums * (divisibleNums + 1))/2 * m;
        return (n*(n+1))/2 - 2*divisibleSum;
    }
};