class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int maxDay = 0;
        int N = events.size();
        for(int i=0;i<N;i++){
            maxDay = max(maxDay, events[i][1]);
        }
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int ans = 0;
        for(int day = 0, idx = 0; day <= maxDay; day++){
            while(idx < N && events[idx][0] <= day){
                minHeap.push(events[idx][1]);
                idx++;
            }
            while(!minHeap.empty() && minHeap.top() < day){
                minHeap.pop();
            }
            if(!minHeap.empty()){
                minHeap.pop();
                ans++;
            }
        }
        return ans;
    }
};