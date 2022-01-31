class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto &x:accounts){
            ans = max(ans,accumulate(x.begin(),x.end(),0));
        }
        return ans;
    }
};