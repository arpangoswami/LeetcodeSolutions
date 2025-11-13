class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, n = s.size(), zeroIntervals = 0, lastChar = '2';
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                if(s[i] != lastChar){
                    zeroIntervals++;
                }
            }else{
                ans += zeroIntervals;
            }
            lastChar = s[i];
        }
        return ans;
    }
};