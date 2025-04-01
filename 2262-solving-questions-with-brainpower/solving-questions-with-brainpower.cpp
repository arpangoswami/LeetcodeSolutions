typedef long long ll;
class Solution {
    ll solve(vector<vector<int>> &questions,int idx,vector<ll> &dp){
        if(idx >= (int)questions.size()){
            return 0LL;
        }
        ll &ans = dp[idx];
        if(ans != -1){
            return ans;
        }
        ans = max(solve(questions,idx+1,dp),questions[idx][0] + solve(questions,idx+questions[idx][1]+1,dp));
        return ans;
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n,-1);
        ll ans = solve(questions,0,dp);
        return ans;
    }
};