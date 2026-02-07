class Solution {
public:
    int minimumDeletions(string s) {
        int cntA = count(s.begin(),s.end(),'a');
        int tillNowB = 0;
        int n = s.size(),ans = n;
        for(int i=0;i<n;i++){
            ans = min(ans, cntA + tillNowB);
            if(s[i] == 'a'){
                cntA--;
            }else{
                tillNowB++;
            }
        }
        ans = min(ans, cntA + tillNowB);
        return ans;
    }
};