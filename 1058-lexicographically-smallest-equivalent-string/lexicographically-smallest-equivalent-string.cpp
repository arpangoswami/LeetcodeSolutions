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
		}else if(height[x_par] > height[y_par]){
			parent[y_par] = x_par;
			sz[x_par] += sz[y_par];
		}else {
            parent[y_par] = x_par;
			sz[x_par] += sz[y_par];
            height[x_par]++;
        }
	}
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Dsu unionAlphabet(26);
        int stringLength = s1.size(),baseStrLength = baseStr.size();
        for(int i=0;i<stringLength;i++){
            unionAlphabet.unite(s1[i]-'a',s2[i]-'a');
        }
        string ans;
        for(int i=0;i<baseStrLength;i++){
            for(char ch='a';ch <=baseStr[i];ch++){
                if(unionAlphabet.findPar(ch-'a') == unionAlphabet.findPar(baseStr[i]-'a')){
                    ans.push_back(ch);
                    break;
                }
            }
        }
        return ans;
    }
};