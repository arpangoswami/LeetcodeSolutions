class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3);
        int n = s.size();
        int ans = 0,left = 0;
        auto isValid = [&](){
            return (freq[0] && freq[1] && freq[2]);
        };
        for(int right = 0;right < n;right++){
            freq[s[right] - 'a']++;
            while(isValid() && left <= right){
                ans += (n - right);
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};