class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int N = nums.size(),left = 0,right = N-1;
        int ans = 0;
        while(left < right){
            ans = max(nums[left++] + nums[right--],ans);
        }
        return ans;
    }
};