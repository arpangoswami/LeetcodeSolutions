class Solution {
    inline bool validityCheck(int freq, int remainder){
        return (freq > 0 && (freq % 2 == remainder));
    }
    int getMinFreq(vector<int> &freq, int remainder) {
        int minFreqNum = 1e3;
        for(int i=0;i<freq.size();i++){
            if(validityCheck(freq[i], remainder) && freq[i] < minFreqNum) {
                minFreqNum = freq[i];
            }
        }
        return minFreqNum;
    }
    int getMaxFreq(vector<int> &freq, int remainder) {
        int maxFreqNum = -1;
        for(int i=0;i<freq.size();i++){
            if(validityCheck(freq[i], remainder) && freq[i] > maxFreqNum) {
                maxFreqNum = freq[i];
            }
        }
        return maxFreqNum;
    }
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        for(int i=0;i<s.size();i++){
            freq[s[i] - 'a']++;
        }
        int maxEven = getMaxFreq(freq, 0);
        int minOdd = getMinFreq(freq, 1);
        int maxOdd = getMaxFreq(freq, 1);
        int minEven = getMinFreq(freq, 0);
        return maxOdd - minEven;
    }
};