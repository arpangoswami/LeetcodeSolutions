class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int N1 = g.size(),N2 = s.size(),ans = 0;
        for(int i=0,j=0;i<N1 && j<N2;j++){
            if(g[i] <= s[j]){
                ans++;
                i++;
            }
        }
        return ans;
    }
};