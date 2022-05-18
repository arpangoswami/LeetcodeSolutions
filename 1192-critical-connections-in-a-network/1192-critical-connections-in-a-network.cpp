class Solution {
    void dfs(int node,int par,vector<bool> &visited,vector<int> &discovery,vector<int> &lowest,vector<vector<int>> &adj_list,int &timeNow,vector<vector<int>> &bridges){
        lowest[node] = timeNow;
        discovery[node] = timeNow;
        timeNow++;
        visited[node] = true;
        for(int child:adj_list[node]){
            if(!visited[child]){
                dfs(child,node,visited,discovery,lowest,adj_list,timeNow,bridges);
                lowest[node] = min(lowest[node],lowest[child]);
                if(lowest[child] > discovery[node]){
                    bridges.push_back({node,child});
                }
            }else if(child != par){
                //back edge
                lowest[node] = min(lowest[node],discovery[child]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n,false);
        vector<int> discovery(n),lowest(n);
        vector<vector<int>> adj_list(n);
        int timeNow = 0;
        for(auto &x:connections){
            int node1 = x[0],node2 = x[1];
            adj_list[node1].push_back(node2);
            adj_list[node2].push_back(node1);
        }
        vector<vector<int>> bridges;
        dfs(0,-1,visited,discovery,lowest,adj_list,timeNow,bridges);
        return bridges;
    }
};