class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxValue(n);
        int maxm = 0;
        for(int i=0;i<n;i++){
            maxValue[i] = maxm = max(maxm, nums[i]);
        }
        vector<int> gcdValue(n);
        for(int i=0;i<n;i++){
            gcdValue[i] = __gcd(maxValue[i], nums[i]);
        }
        sort(gcdValue.begin(), gcdValue.end(), greater<int>());
        long long ans = 0;
        for(int i=0;i<(n/2);i++){
            ans += __gcd(gcdValue[i], gcdValue[n-1-i]);
        }
        return ans;
    }
};