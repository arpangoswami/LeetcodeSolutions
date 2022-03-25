class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](vector<int> &v1,vector<int> &v2){
            return (v1[0] - v1[1]) < (v2[0] - v2[1]); 
        });
        int ans = 0;
        int n = (costs.size())/2;
        for(int i=0;i<(2*n);i++){
            if(i < n){
                ans += costs[i][0];
            }else{
                ans += costs[i][1];
            }
        }
        return ans;
    }
};