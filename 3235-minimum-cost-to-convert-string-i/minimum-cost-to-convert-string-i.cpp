using ll = long long;
using pii = pair<int,int>;
class Solution {
    vector<ll> getCost(int sv,vector<vector<ll>> &adjMat) {
        vector<ll> dis(26, INT_MAX);
        priority_queue<pii,vector<pii>,greater<pii>> minHeap;
        minHeap.push({0, sv});
        dis[sv] = 0;
        while(!minHeap.empty()){
            int v = minHeap.top().second;
            int dist = minHeap.top().first;
            minHeap.pop();
            if(dist != dis[v]){
                continue;
            }
            for(int i=0;i<26;i++){
                if(v == i){
                    continue;
                }
                if(adjMat[v][i] != INT_MAX){
                    int totalDist = dis[v] + adjMat[v][i];
                    int nb = i;
                    if(dis[nb] > totalDist){
                        dis[nb] = totalDist;
                        minHeap.push({totalDist, nb});
                    }
                }
            }
        }
        return dis;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll ans = 0l;
        vector<vector<ll>> adjMat(26, vector<ll>(26, INT_MAX));
        int n = original.size();
        for(int i=0;i<26;i++){
            adjMat[i][i] = 0;
        }
        for(int i=0;i<n;i++){
            int u = original[i] - 'a', v = changed[i] - 'a', price = cost[i];
            adjMat[u][v] = min(adjMat[u][v], (ll)price);
        }
        vector<vector<ll>> minCost(26);
        for(int i=0;i<26;i++){
            minCost[i] = getCost(i, adjMat);
        }
        n = source.size();
        for(int i=0;i<n;i++) {
            int src = source[i] - 'a',dest = target[i] - 'a';
            if(minCost[src][dest] >= INT_MAX){
                return -1;
            }
            ans += minCost[src][dest];
        }
        return ans;
    }
};