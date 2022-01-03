class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1);
        for(auto x:trust){
            int u = x[0],v = x[1];
            count[u] -= (n*n);
            count[v]++;
        }
        for(int i=1;i<=n;i++){
            if(count[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};