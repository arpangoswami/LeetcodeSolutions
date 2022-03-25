class DSU{
    int n;
    vector<int> par;
    vector<int> ranks;
    int components;
public:
    DSU(int _n){
        n = _n;
        components = n;
        par.resize(n+1,0);
        ranks.resize(n+1,0);
        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }
    int findPar(int v){
        if(par[v] == v){
            return v;
        }
        int parent = findPar(par[v]);
        par[v] = parent;
        return parent;
    }
    void join(int x,int y){
        int x_rep = findPar(x),y_rep = findPar(y);
        if(x_rep == y_rep){
            return;
        }
        components--;
        if(ranks[x_rep] > ranks[y_rep]){
            par[y_rep] = x_rep;
        }else if(ranks[x_rep] < ranks[y_rep]){
            par[x_rep] = y_rep;
        }else{
            par[y_rep] = x_rep;
            ranks[x_rep]++;
        }
    }
    int getComponents(){
        return components;
    }
};
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(),connections.end(),[](vector<int> &v1,vector<int> &v2){
           return v1[2] < v2[2]; 
        });
        int ans = 0;
        DSU d(n);
        int picked = 0;
        for(vector<int> &v:connections){
            int x = v[0],y = v[1];
            if(d.findPar(x) != d.findPar(y)){
                d.join(x,y);
                ans += v[2];
                picked++;
            }
            if(picked == n-1){
                break;
            }
        }
        if(d.getComponents() > 1){
            return -1;
        }
        return ans;
    }
};