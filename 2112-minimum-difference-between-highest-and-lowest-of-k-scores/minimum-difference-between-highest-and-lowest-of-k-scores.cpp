class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxDiff = nums.back();
        for(int i=0;i<=(n-k);i++){
            maxDiff = min(maxDiff, nums[i+k-1] - nums[i]);
        }
        return maxDiff;
    }
};