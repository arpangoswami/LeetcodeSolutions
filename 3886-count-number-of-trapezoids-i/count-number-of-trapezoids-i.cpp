using ll = long long;
class Solution {
    constexpr static int MOD = 1e9 + 7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
        for(vector<int> &v: points){
            mp[v[1]]++;
        }
        vector<int> totalPairs;
        ll totalSum = 0;
        for(auto it: mp){
            if(it.second >= 2){
                ll nC2 = ((ll)(it.second) * (ll)(it.second - 1))/2;
                totalSum += nC2;
                totalPairs.push_back(nC2);
            }
        }
        int ans = 0l;
        for(int x:totalPairs){
            totalSum -= x;
            ll add = (x * totalSum) % MOD;
            ans += add;
            ans %= MOD;
        }
        return ans;
    }
};