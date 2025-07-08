class Solution {
    int binSearch(int minStartTime,int low,vector<vector<int>> &events){
        int n = events.size(),high = n-1,ans = n;
        while(low <= high){
            int mid = (low+high)/2;
            if(events[mid][0] > minStartTime){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int recDp(int idx,int eventsRemaining,vector<vector<int>> &events,vector<vector<int>> &dp){
        if(idx >= events.size() || eventsRemaining <= 0){
            return 0;
        }
        if(dp[idx][eventsRemaining] != -1){
            return dp[idx][eventsRemaining];
        }
        int &ans = dp[idx][eventsRemaining] = 0;
        ans = recDp(idx+1,eventsRemaining,events,dp);
        if(eventsRemaining > 0){
            int idxFind = binSearch(events[idx][1],idx+1,events);
            ans = max(ans,recDp(idxFind,eventsRemaining-1,events,dp) + events[idx][2]);
        }
        return ans;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),[](vector<int> &event1,vector<int> &event2){
            if(event1[0] == event2[0]){
                return event1[1] < event2[1];
            }
            return event1[0] < event2[0];
        });
        int n = events.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return recDp(0,k,events,dp);
    }
};