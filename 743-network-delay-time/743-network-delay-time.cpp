typedef pair<int,int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj_list(n+1);
        for(auto &x:times){
            adj_list[x[0]].push_back({x[1],x[2]});
        }
        vector<int> distances(n+1,INT_MAX);
        distances[0] = distances[k] = 0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int v = pq.top().second,d = pq.top().first;
            pq.pop();
            if(distances[v] != d){
                continue;
            }
            for(auto &x:adj_list[v]){
                if(distances[x.first] > distances[v] + x.second){
                    distances[x.first] =  distances[v] + x.second;
                    pq.push({distances[x.first],x.first});
                }
            }
        }
        int maxm = *max_element(distances.begin(),distances.end());
        return maxm > 1e9 ? -1 : maxm;
    }
};