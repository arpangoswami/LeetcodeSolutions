class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> totalTime(n);
        for(int i=0;i<n;i++){
            totalTime[i] = {plantTime[i],growTime[i]};
        }
        sort(totalTime.begin(),totalTime.end(),[](auto &p1,auto &p2){
            return p1.second > p2.second;
        });
        int ans = 0;
        int daysSpent = 0;
        for(int i=0;i<n;i++){
            daysSpent += totalTime[i].first;
            ans = max(ans,daysSpent + totalTime[i].second);
        }
        return ans;
    }
};