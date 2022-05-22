class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(),ans = 0;
        for(int i=0;i<n;i++){
            int left = i,right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                ans++;
                left--;
                right++;
            }
            left = i-1,right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};