class Solution {
    bool dfs(int sv,vector<int> &visited,vector<vector<int>> &graph,int color){
        visited[sv] = color;
        for(int &nb:graph[sv]){
            if(visited[nb] == color || (!visited[nb] && !dfs(nb,visited,graph,color*(-1)))){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n);
        for(int i=0;i<n;i++){
            if(!visited[i] && !dfs(i,visited,graph,1)){
                return false;
            }
        }
        return true;
    }
};