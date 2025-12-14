class Solution {
    const int MOD = 1e9+7;
    int recDp(int idx,string &corridor,int numSeats,vector<vector<int>> &dp){
        if(idx == corridor.size()){
            return numSeats == 2;
        }
        if(dp[idx][numSeats] != -1){
            return dp[idx][numSeats];
        }
        int &ans = dp[idx][numSeats] = 0;
        if(corridor[idx] == 'S'){
            if(numSeats == 2){
                ans = recDp(idx+1,corridor,1,dp);
            }else{
                ans = recDp(idx+1,corridor,numSeats+1,dp);
            }
        }else{
            ans = recDp(idx+1,corridor,numSeats,dp);
            if(numSeats == 2)
            ans += recDp(idx+1,corridor,0,dp);
            ans %= MOD;
        }
        return ans;
    }
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return recDp(0,corridor,0,dp);
    }
};