using pii = pair<int,int>;
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int N = startTime.size();
        vector<int> breaks;
        int prevEndTime = 0;
        for(int i=0;i<N;i++){
            breaks.push_back(startTime[i] - prevEndTime);
            prevEndTime = endTime[i];
        }
        breaks.push_back(eventTime - prevEndTime);
        int currWindow = 0;
        for(int i=0;i<=k && i<breaks.size();i++){
            currWindow += breaks[i];
        }
        int maxWindow = currWindow;
        for(int i=k+1;i<breaks.size();i++){
            currWindow -= breaks[i-k-1];
            currWindow += breaks[i];
            maxWindow = max(currWindow, maxWindow);
        }
        return maxWindow;
    }
};