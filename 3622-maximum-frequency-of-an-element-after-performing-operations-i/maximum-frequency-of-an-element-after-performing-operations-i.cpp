class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int originalSize = 1e5 + 2;
        vector<int> prefMap(originalSize);
        vector<int> freqMap(originalSize);
        int startIdx = originalSize+1,endIdx = 0;
        for(int x:nums){
            freqMap[x]++;
            int xLow = max(1, x - k), xHigh = min(x+k+1, originalSize-1);
            prefMap[xLow]++;
            prefMap[xHigh]--;
            startIdx = min(startIdx, xLow);
            endIdx = max(endIdx, xHigh);
        }
        int ans = *max_element(freqMap.begin(), freqMap.end()), cumulativeFrequency = 0;
        for(int i=startIdx;i<=endIdx;i++){
            cumulativeFrequency += prefMap[i];
            int possibleX = freqMap[i] + min(cumulativeFrequency - freqMap[i], numOperations);
            ans = max(ans, possibleX);
        }
        return ans;
    }
};