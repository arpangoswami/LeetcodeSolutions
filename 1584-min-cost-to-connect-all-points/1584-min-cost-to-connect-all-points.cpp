class Solution {
    struct edge{
        int s;
        int e;
        int cost;
        edge() : s(-1),e(-1),cost(-1){}
        edge(int st,int ed,int cst): s(st),e(ed),cost(cst){}
    };
    static bool cmp(edge &e1,edge &e2){
        return e1.cost < e2.cost;
    }
    int findParent(int x,vector<int> &parent){
        if(x == parent[x]){
            return x;
        }
        int temp = findParent(parent[x],parent);
        parent[x] = temp;
        return temp;
    }
    void unionRank(int x,int y,vector<int> &parent,vector<int> &rank){
        int x_rep = findParent(x,parent),y_rep = findParent(y,parent);
        if(x_rep == y_rep){
            return;
        }
        if(rank[x_rep] < rank[y_rep]){
            parent[x_rep] = y_rep;
        }else if(rank[x_rep] > rank[y_rep]){
            parent[y_rep] = x_rep;
        }else{
            parent[x_rep] = y_rep;
            rank[y_rep]++;
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        vector<edge> graph;
        for(int i=0;i<(n-1);i++){
            for(int j=i+1;j<n;j++){
                edge temp = edge(i,j,abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]));
                graph.push_back(temp);
            }
        }
        sort(graph.begin(),graph.end(),cmp);
        int cnt = 0;
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        vector<int> rank(n);
        int i = 0;
        while(cnt < (n-1)){
            edge temp = graph[i];
            int x_rep = findParent(temp.s,parent);
            int y_rep = findParent(temp.e,parent);
            if(x_rep!=y_rep){
                ans += temp.cost;
                unionRank(x_rep,y_rep,parent,rank);
                cnt++;
            }
            i++;
        }
        return ans;
    }
};