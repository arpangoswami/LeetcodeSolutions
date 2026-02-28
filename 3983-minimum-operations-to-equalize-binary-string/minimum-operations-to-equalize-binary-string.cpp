class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        vector<int> dist(n+1, INT_MAX);
        int cntZero = count(s.begin(), s.end(), '0');
        vector<set<int>> nodeSets(2);
        for(int i=0;i<=n;i++){
            nodeSets[i%2].insert(i);
        }
        queue<int> q;
        q.push(cntZero);
        dist[cntZero] = 0;
        nodeSets[cntZero % 2].erase(cntZero);
        while(!q.empty()){
            cntZero = q.front();
            q.pop();
            int minZero = max(0, k - n + cntZero), maxZero = min(k, cntZero);
            int lNode = cntZero + k - 2*maxZero, rNode = cntZero + k - 2*minZero;
            set<int>& nodeSet = nodeSets[lNode % 2];
            for(auto iter = nodeSet.lower_bound(lNode); iter != nodeSet.end() && *iter <= rNode;){
                int nextZero = *iter;
                dist[nextZero] = 1+dist[cntZero];
                q.push(nextZero);
                iter = next(iter);
                nodeSet.erase(nextZero);
            }
        }
        return dist[0] == INT_MAX ? -1 : dist[0];
    }
};