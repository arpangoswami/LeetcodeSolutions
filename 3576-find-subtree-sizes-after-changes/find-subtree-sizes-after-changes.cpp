class Solution {
    void dfsChangeParent(vector<vector<int>> &adjList, const string &s, vector<int> &nearestParent, vector<vector<int>> &newAdjList, int node, int par){
        int ch = s[node] - 'a';
        int prev = nearestParent[ch];
        if(nearestParent[ch] != -1){
            int newParent = nearestParent[s[node] - 'a'];
            newAdjList[newParent].push_back(node);
        }else if (par != -1){
            newAdjList[par].push_back(node);
        }
        nearestParent[s[node] - 'a'] = node;
        for(int x:adjList[node]){
            dfsChangeParent(adjList, s, nearestParent, newAdjList, x, node);
        }
        nearestParent[s[node] - 'a'] = prev;
    }
    int dfsSubtreeSize(vector<vector<int>> &newAdjList, int node, vector<int> &ans){
        int sum = 1;
        for(int x:newAdjList[node]){
            sum += dfsSubtreeSize(newAdjList, x, ans);
        }
        ans[node] = sum;
        return sum;
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adjList(n);
        for(int i=1;i<n;i++){
            adjList[parent[i]].push_back(i);
        }
        vector<int> nearestParent(26, -1);
        vector<vector<int>> newAdjList(n);
        dfsChangeParent(adjList, s, nearestParent, newAdjList, 0, -1);
        vector<int> ans(n);
        dfsSubtreeSize(newAdjList, 0, ans);
        return ans;
    }
};