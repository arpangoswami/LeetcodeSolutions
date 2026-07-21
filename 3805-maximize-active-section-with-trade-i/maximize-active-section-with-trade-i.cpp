class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size(), ans = 0;
        int prevZero = INT_MIN, zeroSum = 0;
        for(int i=0;i<n;){
            if(s[i] == '1'){
                i++;
                ans++;
                continue;
            }
            int currZero = 0;
            while(i < n && s[i] == '0'){
                currZero++;
                i++;
            }
            zeroSum = max(zeroSum, currZero+prevZero);
            prevZero = currZero;
        }
        ans += zeroSum;
        return ans;
    }
};