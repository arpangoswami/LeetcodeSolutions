class Solution {
    int recDp(vector<vector<int>> &workers,vector<vector<int>> &bikes,int picked,int state,int n,int m,vector<int> &dp){
        if(picked == n){
            return 0;
        }
        if(dp[state] != -1){
            return dp[state];
        }
        int &ans = dp[state];
        ans = INT_MAX;
        for(int i=0;i<m;i++){
            if(((state >> i) & 1) == 0){
                int val = abs(bikes[i][0] - workers[picked][0]) + abs(bikes[i][1] - workers[picked][1]) + recDp(workers,bikes,picked+1,state | (1 << i),n,m,dp);
                ans = min(ans,val);
            }
        }
        return ans;
    }
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(),m = bikes.size();
        vector<int> dp(1 << m,-1);
        return recDp(workers,bikes,0,0,n,m,dp);
    }
};