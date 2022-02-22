class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long multiplier = 1,ans = 0,n = columnTitle.size();
        for(int i=n-1;i>=0;i--){
            long long add = columnTitle[i] - 'A' + 1;
            add *= multiplier;
            ans += add;
            multiplier *= 26LL;
        }
        return ans;
    }
};