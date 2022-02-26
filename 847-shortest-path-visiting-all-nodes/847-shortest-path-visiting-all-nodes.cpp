class Solution {
    int recDp(int start,int visited,vector<vector<int>> &graph,vector<vector<int>> &dp,int n){
        if(visited == (1 << n) - 1){
            return 0;
        }
        if(dp[start][visited] != -1){
            return dp[start][visited];
        }
        dp[start][visited] = 1e9;
        for(int x:graph[start]){
            if(((visited >> x) & 1) == 0){
                int ans1 = recDp(x,visited,graph,dp,n);
                int ans2 = recDp(x,visited | (1 << x),graph,dp,n);
                dp[start][visited] = min(dp[start][visited],min(ans1,ans2)+1);
            }
        }
        return dp[start][visited];
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int totalState = 1 << n;
        vector<vector<int>> dp(n,vector<int>(totalState,-1));
        int ans = 1e9;
        for(int i=0;i<n;i++){
            ans = min(ans,recDp(i,1 << i,graph,dp,n));
        }
        return ans;
    }
};