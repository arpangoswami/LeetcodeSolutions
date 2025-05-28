class Solution {
    int findNeighbours(int start, vector<vector<int>> &adjList, int maxDist) {
        if(maxDist < 0){
            return 0;
        }
        queue<pair<int,int>> q;
        q.push({start, 0});
        int ans = 0;
        vector<bool> visited(adjList.size());
        visited[start] = true;
        while(!q.empty()){
            int node = q.front().first,dist = q.front().second;
            q.pop();
            ans++;
            if(dist >= maxDist){
                continue;
            }
            for(int &x:adjList[node]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push({x, dist+1});
                }
            }
        }
        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // BFS from each node in Tree 1 to find no. of vertices within distance k -> ans1
        // BFS from each node in Tree 2 to find no. of vertices within distance k - 1. Find the vertex with maximum such vertices -> ans2
        // ans = ans1 + ans2
        int n = edges1.size() + 1, m = edges2.size()+1;
        vector<vector<int>> adjList1(n);
        vector<vector<int>> adjList2(m);
        vector<int> ans(n);
        for(const vector<int> &v: edges1){
            adjList1[v[0]].push_back(v[1]);
            adjList1[v[1]].push_back(v[0]);
        }
        for(const vector<int> &v: edges2){
            adjList2[v[0]].push_back(v[1]);
            adjList2[v[1]].push_back(v[0]);
        }
        int maxV = -1,maxNb = 0;
        for(int i=0;i<m;i++){
            int nb = findNeighbours(i, adjList2, k-1);
            if(nb > maxNb){
                maxV = i;
                maxNb = nb;
            }
        }
        for(int i=0;i<n;i++){
            ans[i] = findNeighbours(i, adjList1, k) + maxNb;
        }
        return ans;
    }
};