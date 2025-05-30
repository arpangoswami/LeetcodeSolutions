class Solution {
    void dfsCalDist(int node,int distanceFromRoot,vector<int> &edges,vector<int> &distanceNodeMap,vector<bool> &visited){
        if(visited[node] || distanceNodeMap[node] < 1e6){
            return;
        }
        distanceNodeMap[node] = distanceFromRoot;
        visited[node] = true;
        if(edges[node] != -1 && !visited[edges[node]]){
            dfsCalDist(edges[node],1+distanceFromRoot,edges,distanceNodeMap,visited);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> distanceNode1(n, 1e6),distanceNode2(n, 1e6);
        int numNodes = edges.size();
        vector<bool> visited(n);
        dfsCalDist(node1,0,edges,distanceNode1,visited);
        fill(visited.begin(),visited.end(),false);
        dfsCalDist(node2,0,edges,distanceNode2,visited);
        int maxDist = 1e6;
        int commonNode = -1;
        for(int i=0;i<n;i++){
            if(distanceNode1[i] < 1e6 && distanceNode2[i] < 1e6 && max(distanceNode1[i], distanceNode2[i]) < maxDist){
                commonNode = i;
                maxDist =  max(distanceNode1[i], distanceNode2[i]);
            }
        }
        return commonNode;
    }
};