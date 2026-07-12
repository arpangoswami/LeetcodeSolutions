class Dsu{
public:
    int n;
    vector<int> parent;
    vector<int> height;
    vector<int> sz;
    Dsu(int _n){
        n = _n;
        parent.resize(n+1);
        height.resize(n+1,0);
        sz.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int getSize(int x){
        return sz[findPar(x)];
    }
    int findPar(int x){
        if(parent[x] == x){
            return x;
        }
        int p = findPar(parent[x]);
        parent[x] = p;
        return p;
    }
    void unite(int x,int y){
        int x_par = findPar(x),y_par = findPar(y);
        if(x_par == y_par){
            return;
        }
        if(height[x_par] < height[y_par]){
            parent[x_par] = y_par;
            sz[y_par] += sz[x_par];
        }else{
            parent[y_par] = x_par;
            sz[x_par] += sz[y_par];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Dsu d(n);
        vector<int> edgeCount(n);
        for(vector<int> &v:edges){
            int x = v[0],y = v[1];
            d.unite(x,y);
            edgeCount[x]++;
        }
        unordered_map<int,int> edgeCountParent;
        for(int i=0;i<n;i++){
            int par = d.findPar(i);
            edgeCountParent[par] += edgeCount[i];
        }
        int ans = 0;
        for(auto it:edgeCountParent){
            int sz = d.getSize(it.first);
            int edges = it.second;
            if(((sz*(sz-1))/2) == edges){
                ans++;
            }
        }
        return ans;
    }
};