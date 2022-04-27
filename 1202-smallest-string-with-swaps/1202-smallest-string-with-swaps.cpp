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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        Dsu d(n);
        for(vector<int> &v:pairs){
            d.unite(v[0],v[1]);
        }
        unordered_map<int,multiset<char>> mp;
        for(int i=0;i<n;i++){
            int v = d.findPar(i);
            mp[v].insert(s[i]);
        }
        string ans;
        for(int i=0;i<n;i++){
            int v = d.findPar(i);
            auto it = mp[v].begin();
            char ch = *it;
            mp[v].erase(it);
            ans.push_back(ch);
        }
        return ans;
    }
};