class Solution {
    bool check(vector<int> freq){
        int count = -1;
        for(int &x:freq){
            if(x > 0){
                if(count != -1 && x != count){
                    return false;
                }
                count = x;
            }
        }
        return true;
    }
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            vector<int> freq(26, 0);
            for(int j=i;j<n;j++){
                freq[s[j] - 'a']++;
                if(!check(freq)){
                    continue;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};