class Solution {
    int getSumOfDigits(int n){
        int sum = 0;
        while(n) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        vector<int> groupMap(46);
        for(int i=1;i<=n;i++){
            int sum = getSumOfDigits(i);
            groupMap[sum]++;
        }
        int maxSize = 0, maxNum = 0;
        for(int i=1;i<=45;i++){
            if(groupMap[i] > maxSize){
                maxSize = groupMap[i];
                maxNum = 1;
            }else if(groupMap[i] == maxSize){
                maxNum++;
            }
        }
        return maxNum;
    }
};