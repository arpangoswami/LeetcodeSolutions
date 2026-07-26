class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + 2, nums.end(), greater<int>());
        int ans1 = nums[0]*nums[1]*nums[2];
        nth_element(nums.begin(), nums.begin() + 1, nums.end());
        int maxm = *max_element(nums.begin(), nums.end());
        int ans2 = nums[0]*nums[1]*maxm;
        return max(ans1, ans2);
    }
};