class Solution {
public:
    string longestPalindrome(string s) {
        int startIdx = 0,maxLen = 1,n = s.size();
        for(int i=0;i<n;i++){
            int left = i-1,right = i+1;
            int len = 1;
            while(left >= 0 && right < n && s[left] == s[right]){
                len += 2;
                left--;
                right++;
            }
            if(len > maxLen){
                maxLen = len;
                startIdx = i - len/2;
            }
            left = i-1,right = i;
            len = 0;
            while(left >= 0 && right < n && s[left] == s[right]){
                len += 2;
                left--;
                right++;
            }
            if(len > maxLen){
                maxLen = len;
                startIdx = i-len/2;
            }
        }
        return s.substr(startIdx,maxLen);
    }
};