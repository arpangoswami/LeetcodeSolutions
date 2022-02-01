class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minm = prices[0],n = prices.size();
        for(int i=1;i<n;i++){
            ans = max(ans,prices[i]-minm);
            minm = min(minm,prices[i]);
        }
        return ans;
    }
};