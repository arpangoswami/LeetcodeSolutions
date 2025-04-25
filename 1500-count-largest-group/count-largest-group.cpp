class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> groupMap(46);
        for(int i=1;i<=n;i++){
            string s = to_string(i);
            int sum = 0;
            for(char &ch:s){
                sum += (ch - '0');
            }
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