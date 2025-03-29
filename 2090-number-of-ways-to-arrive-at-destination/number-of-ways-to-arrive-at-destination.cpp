using ll = long long;
ll MOD = 1e9 + 7;
class Solution {
    ll getShortestPathCount(int n, vector<vector<pair<ll,ll>>> &adjList){
        vector<ll> dist(n, 1e15);
        dist[0] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> minHeap;
        vector<ll> ways(n, 0);
        ways[0] = 1;
        minHeap.push({0, 0});
        while(!minHeap.empty()){
            int node = minHeap.top().second;
            ll distance = minHeap.top().first;
            minHeap.pop();
            if(distance > dist[node]){
                continue;
            }
            for(pair<ll,ll> &v:adjList[node]){
                ll nb = v.first, distanceNb = v.second;
                ll newTime = distance + distanceNb;
                if(newTime < dist[nb]){
                    dist[nb] = newTime;
                    ways[nb] = ways[node];
                    minHeap.push({newTime, nb});
                }else if(newTime == dist[nb]){
                    ways[nb] += ways[node];
                    ways[nb] %= MOD;
                }
            }
        }
        return ways[n-1];
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> adjList(n);
        for(vector<int> &v:roads){
            adjList[v[0]].push_back({v[1], v[2]});
            adjList[v[1]].push_back({v[0], v[2]});
        }
        return getShortestPathCount(n, adjList);
    }
};