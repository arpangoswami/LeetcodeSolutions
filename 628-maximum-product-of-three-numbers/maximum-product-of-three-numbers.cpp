class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans1 = nums[0]*nums[1]*nums.back();
        int ans2 = nums[n-3]*nums[n-2]*nums[n-1];
        return max(ans1, ans2);

    }
};