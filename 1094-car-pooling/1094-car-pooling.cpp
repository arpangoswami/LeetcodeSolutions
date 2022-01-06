class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int members = 0,n = trips.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        sort(trips.begin(),trips.end(),[](vector<int> &v1,vector<int> &v2){
            return v1[1] < v2[1];
        });
        for(int i=0;i<n;i++){
            while(!pq.empty() && (pq.top()).first <= trips[i][1]){
                members -= (pq.top()).second;
                pq.pop();
            }
            members += trips[i][0];
            if(members > capacity){
                return false;
            }
            pq.push({trips[i][2],trips[i][0]});
        }
        return true;
    }
};