using ll = long long;
using pii = pair<int,int>;
class Solution {
    const ll INF = 1e15;
    ll recDp(int robIdx, int facIdx,vector<int> &robot, vector<ll> &factory, vector<vector<ll>> &dp){
        int N = robot.size(), M = factory.size();
        if (robIdx == N){
            return 0;
        }
        if(facIdx == M){
            return INF;
        }
        if(dp[robIdx][facIdx] != -1){
            return dp[robIdx][facIdx];
        }
        ll ans1 = recDp(robIdx, facIdx+1, robot, factory, dp);
        ll ans2 = (ll)abs(factory[facIdx] - robot[robIdx]) + recDp(robIdx+1, facIdx+1, robot, factory, dp);
        return dp[robIdx][facIdx] = min(ans1, ans2);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        int N = robot.size(), M = factory.size();
        vector<ll> factories;
        for(int i=0;i<M;i++){
            for(int j=0;j<factory[i][1];j++){
                factories.push_back(factory[i][0]);
            }
        }
        sort(factories.begin(),factories.end());
        M = factories.size();
        vector<vector<ll>> dp(N+1, vector<ll> (M+1, -1));
        return recDp(0,0,robot,factories, dp);
    }
};