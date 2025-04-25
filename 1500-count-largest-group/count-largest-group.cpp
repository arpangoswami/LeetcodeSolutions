class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> groupMap;
        for(int i=1;i<=n;i++){
            string s = to_string(i);
            int sum = 0;
            for(char &ch:s){
                sum += (ch - '0');
            }
            groupMap[sum]++;
        }
        int maxSize = 0, maxNum = 0;
        for(auto it:groupMap){
            if(it.second > maxSize){
                maxSize = it.second;
                maxNum = 1;
            }else if(it.second == maxSize){
                maxNum++;
            }
        }
        return maxNum;
    }
};