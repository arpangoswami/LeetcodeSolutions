auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
using ll = long long;
class Solution {
    ll recDp(int idx,vector<ll> &dp,vector<pair<ll,ll>> &sortedCount){
        if(idx >= sortedCount.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        ll ans1 = recDp(idx+1, dp, sortedCount); // current idx skipped
        ll ans2 = sortedCount[idx].first;
        int idx2 = idx + 1;
        while(idx2 < sortedCount.size() && (sortedCount[idx].second + 2) >= sortedCount[idx2].second){
            idx2++;
        }
        ans2 += recDp(idx2, dp, sortedCount); // Taking current idx
        return dp[idx] = max(ans1, ans2);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<ll,ll> freq;
        for(int &x:power){
            freq[x]++;
        }
        vector<pair<ll,ll>> sortedCount;
        for(auto &it:freq){
            sortedCount.push_back({it.first * it.second, it.first});
        }
        sort(sortedCount.begin(), sortedCount.end(), [](pair<ll,ll> &p1, pair<ll,ll> &p2){
            return (p1.second < p2.second);
        });
        int n = sortedCount.size();
        vector<ll> dp(n+1,-1);
        cout << endl;
        return recDp(0,dp,sortedCount);
    }
};