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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        Dsu d(n);
        for(int i=1;i<n;i++){
            if((nums[i] - nums[i-1]) <= maxDiff){
                d.unite(i, i-1);
            }
        }
        int N = queries.size();
        vector<bool> ans(N);
        for(int i=0;i<N;i++){
            if(d.findPar(queries[i][0]) == d.findPar(queries[i][1])){
                ans[i] = true;
            }else{
                ans[i] = false;
            }
        }
        return ans;
    }
};