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
	void unite(int x, int y){
    int x_par = findPar(x), y_par = findPar(y);
    if(x_par == y_par){
        return;
    }
    if(height[x_par] < height[y_par]){
        parent[x_par] = y_par;
        sz[y_par] += sz[x_par];
    } else if(height[x_par] > height[y_par]){
        parent[y_par] = x_par;
        sz[x_par] += sz[y_par];
    } else {
        parent[y_par] = x_par;
        sz[x_par] += sz[y_par];
        height[x_par]++;
    }
}
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        Dsu d(n);
        for(vector<int> &v:allowedSwaps){
            d.unite(v[0], v[1]);
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[d.findPar(i)].push_back(i);
        }
        int ans = 0;
        for(auto it:mp){
            const vector<int> &v = it.second;
            vector<int> a,b;
            for(int x:v){
                a.push_back(source[x]);
                b.push_back(target[x]);
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            int aStart = 0, bStart = 0;
            for(;aStart < v.size() && bStart < v.size();){
                if(a[aStart] == b[bStart]){
                    aStart++;
                    bStart++;
                    continue;
                }else if(a[aStart] < b[bStart]){
                    ans++;
                    aStart++;
                }else{
                    bStart++;
                }
            }
            ans += (v.size() - aStart);
        }
        return ans;
    }
};