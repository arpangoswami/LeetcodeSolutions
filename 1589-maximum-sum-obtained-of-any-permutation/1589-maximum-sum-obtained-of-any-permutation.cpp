typedef long long ll;
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        const ll MOD = 1e9+7;
        int n = nums.size();
        vector<int> freq(n);
        for(auto &x:requests){
            int start = x[0],finish = x[1];
            freq[start]++;
            if(finish < (n-1)){
                freq[finish+1]--;
            }
        }
        for(int i=1;i<n;i++){
            freq[i] += freq[i-1];
        }
        sort(freq.begin(),freq.end(),greater<int>());
        sort(nums.begin(),nums.end(),greater<int>());
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans += (ll)freq[i]*(ll)nums[i];
            ans %= MOD;
        }
        return ans;
    }
};