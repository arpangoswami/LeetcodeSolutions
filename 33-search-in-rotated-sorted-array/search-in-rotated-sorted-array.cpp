class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int low = 0;
        int high = length-1;
        while(low<=high){
            int mid = low + ((high-low)>>1);
            if(target == nums[mid]){
                return mid;
            }
            if(nums[mid]<nums[high]){
                if(target > nums[mid] && target<=nums[high]){
                    low = mid+1;                    
                }
                else{
                    high = mid-1;
                }
            }
            else{
                if(target >=nums[low] && target<nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
                
            }
        }
        return -1;
    }
};