class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxValue = *max_element(nums.begin(), nums.end());
        int minValue = *min_element(nums.begin(), nums.end());
        long long ans = (long long)(maxValue - minValue) * (long long)k;
        return ans;
    }
};