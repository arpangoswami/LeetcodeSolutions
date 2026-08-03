int inf = 5e8+1;
class Solution {
public:
    int solve(int i,int n,vector<int> &val,vector<int> &dp,vector<int> &suffSum){
        if(i == n){
            return dp[i] = 0;
        }
        if(dp[i] != -inf){
            return dp[i];
        }
        int maxIdx = min(i+2,n-1);
        int s = 0,ans = -inf;
        for(int j=i;j<=maxIdx;j++){
            s+=val[j];
            int fromSub = (j == n-1) ? 0 : suffSum[j+1];
            ans = max(ans,s + fromSub - solve(j+1,n,val,dp,suffSum));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& value) {
        int n = value.size();
        vector<int> dp(n+1,-inf);
        vector<int> suffSum(n);
        suffSum[n-1] = value[n-1];
        for(int i=n-2;i>=0;i--){
            suffSum[i] = suffSum[i+1] + value[i];
        }
        int alice = solve(0,n,value,dp,suffSum),bob = suffSum[0] - alice;
        if(alice > bob){
            return "Alice";
        }else if(alice < bob){
            return "Bob";
        }
        return "Tie";
    }
};