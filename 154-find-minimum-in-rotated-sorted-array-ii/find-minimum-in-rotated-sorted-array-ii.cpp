class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size() - 1;
        while(low < high){
            int mid = (low + high)/2;
            if(nums[low] < nums[high]){
                return nums[low];
            }
            if(nums[low] < nums[mid]){
                low = mid;
            }else if(nums[low] > nums[mid]){
                high = mid;
            }else{
                low++;
            }
        }
        return (nums[low] > nums[high]) ? nums[low] : nums[high];
    }
};