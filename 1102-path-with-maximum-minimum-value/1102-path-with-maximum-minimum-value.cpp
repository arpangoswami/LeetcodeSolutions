class Dsu{
    int n;
	vector<int> parent;
	vector<int> height;
	vector<int> sz;
public:
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
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    bool isSafe(int x,int y,int m,int n,vector<vector<bool>> &visited){
        return ((x >= 0) && (y >= 0) && (x < m) && (y < n) && visited[x][y]);
    }
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<pair<int,int>> gridValues(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                gridValues[i*n+j] = {grid[i][j],i*n+j}; 
            }
        }
        sort(gridValues.begin(),gridValues.end(),greater<pair<int,int>>());
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        Dsu d(m*n);
        for(int i=0;i<(m*n);i++){
            int x = gridValues[i].second/n,y = gridValues[i].second % n;
            visited[x][y] = true;
            for(int k=0;k<4;k++){
                int nx = x+dx[k],ny = y+dy[k];
                if(isSafe(nx,ny,m,n,visited)){
                    d.unite(gridValues[i].second,nx*n+ny);
                }
            }
            if(d.findPar(0) == d.findPar(m*n-1)){
                return gridValues[i].first;
            }
        }
        return INT_MIN;
    }
};