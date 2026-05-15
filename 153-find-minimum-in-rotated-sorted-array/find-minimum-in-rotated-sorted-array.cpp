class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size() - 1;
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums[low]<nums[high]){
            return nums[0];
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(mid>0 && nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            if(nums[mid]<nums[high]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
        
    }
};