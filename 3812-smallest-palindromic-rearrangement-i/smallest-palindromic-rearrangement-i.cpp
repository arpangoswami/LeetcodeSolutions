class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26);
        char odd = '$';
        for(char &ch:s){
            freq[ch - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i] % 2){
                odd = 'a' + i;
            }
        }
        vector<char> ans(n);
        if(n % 2){
            ans[n/2] = odd;
            freq[odd - 'a']--;
        }
        int lastIdx = 0;
        for(int i=0;i<n/2;i++){
            while(lastIdx < 26 && freq[lastIdx] == 0){
                lastIdx++;
            }
            ans[i] = 'a' + lastIdx;
            ans[n - 1 - i] = ans[i];
            freq[lastIdx] -= 2;
        }
        return string(ans.begin(), ans.end());
    }
};