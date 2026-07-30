class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(char ch:word){
            freq[ch - 'a']++;
        }
        sort(freq.begin(), freq.end());
        int ans = 0, add = 1, batchSize = 0;
        for(int i=25;i>=0;i--){
            ans += (freq[i] * add);
            batchSize++;
            if(batchSize == 8){
                add++;
                batchSize = 0;
            }
        }
        return ans;
    }
};