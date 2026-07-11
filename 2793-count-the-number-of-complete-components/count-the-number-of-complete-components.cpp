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
        set<pair<int,int>> st;
        Dsu d(n);
        for(vector<int> &v:edges){
            int x = v[0],y = v[1];
            if(x > y){
                swap(x,y);
            }
            st.insert({x,y});
            d.unite(x,y);
        }
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            int par = d.findPar(i);
            mp[par].push_back(i);
        }
        int ans = 0;
        for(auto &it:mp){
            vector<int> &v = it.second;
            sort(v.begin(),v.end());
            int N = v.size();
            bool flag = true;
            
            for(int i=0;i<(N-1);i++){
                for(int j=i+1;j<N;j++){
                    if(!st.count({v[i],v[j]})){
                        flag = false;
                        break;
                    }
                }
                if(flag == false){
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};