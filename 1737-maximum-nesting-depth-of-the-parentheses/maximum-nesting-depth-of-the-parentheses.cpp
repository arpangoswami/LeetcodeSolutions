class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, maxCnt = 0;
        for(char &ch:s){
            if(ch == '('){
                cnt++;
            }else if(ch == ')'){
                cnt--;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};