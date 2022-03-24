class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(),m = bikes.size();
        vector<array<int,3>> pairs(n*m);
        int k = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pairs[k++] = {abs(workers[i][0] - bikes[j][0])+abs(workers[i][1] - bikes[j][1]),i,j};
            }
        }
        sort(pairs.begin(),pairs.end());
        vector<int> ans(n);
        vector<bool> picked(n),bikePicked(m);
        for(int i=0;i<(n*m);i++){
            int idx1 = pairs[i][1],idx2 = pairs[i][2];
            if(!picked[idx1] && !bikePicked[idx2]){
                ans[idx1] = idx2;
                bikePicked[idx2] = true;
                picked[idx1] = true;
            }
        }
        return ans;
    }
};