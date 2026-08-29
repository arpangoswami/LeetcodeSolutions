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
		if(height[x_par] == height[y_par]){
			height[x_par]++;
		}
	}
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> copy(n);
        for(int i=0;i<n;i++){
            copy[i] = {nums[i], i};
        }
        sort(copy.begin(), copy.end());
        Dsu d(n);
        for(int i=1;i<n;i++){
            if((copy[i].first - copy[i-1].first) <= limit){
                d.unite(copy[i].second, copy[i-1].second);
            }
        }
        unordered_map<int,vector<int>> parent;
        for(int i=0;i<n;i++){
            parent[d.findPar(i)].push_back(nums[i]);
        }
        for(auto &it:parent){
            sort(it.second.begin(), it.second.end(), greater<int>());
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int par = d.findPar(i);
            ans[i] = parent[par].back();
            parent[par].pop_back();
        }
        return ans;
    }
};