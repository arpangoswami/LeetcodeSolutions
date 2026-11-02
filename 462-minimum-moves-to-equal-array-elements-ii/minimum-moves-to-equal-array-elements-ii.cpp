class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        auto cost = [&](int midIdx) -> long long {
            long long mid = nums[midIdx];
            long long left = accumulate(nums.begin(), nums.begin() + midIdx, 0LL);
            long long right = accumulate(nums.begin() + midIdx + 1, nums.end(), 0LL);
            return (long long)midIdx * mid - left + right - (long long)(n - midIdx - 1) * mid;
        };

        long long ans = cost(n / 2);
        return (int)ans;
    }
};