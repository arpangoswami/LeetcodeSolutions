class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            int val = pq.top();
            pq.pop();
            pq.push(val+1);
        }
        long long ans = 1LL;
        while(!pq.empty()){
            ans *= pq.top();
            pq.pop();
            const int MOD = (1e9+7);
            ans %= MOD;
        }
        return ans;
    }
};