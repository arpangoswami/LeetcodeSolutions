class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, n = nums.size(), maxWindow = 1;
        for(int right = 0;right<n;right++){
            long long product = (long long)k * (long long)nums[left];
            while(left < right && product < nums[right]){
                left++;
                product = (long long)k * (long long)nums[left];
            }
            maxWindow = max(maxWindow, right - left + 1);
        }
        return n - maxWindow;
    }
};