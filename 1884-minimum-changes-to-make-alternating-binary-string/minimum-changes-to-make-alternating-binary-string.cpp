class Solution {
public:
    int minOperations(string s) {
        int n = s.size(),ans = n,cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] - '0' != i % 2){
                cnt++;
            }
        }
        ans = min(ans,cnt);
        cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] - '0' != (i%2) ^ 1){
                cnt++;
            }
        }
        ans = min(ans,cnt);
        return ans;
    }
};