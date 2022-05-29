class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freq1(26),freq2(26);
        for(char c:s){
            freq1[c-'a']++;
        }
        for(char c:target){
            freq2[c-'a']++;
        }
        int ans = INT_MAX;
        for(char c:target){
            int idx = c-'a';
            ans = min(ans,freq1[idx]/freq2[idx]);
        }
        return ans;
    }
};