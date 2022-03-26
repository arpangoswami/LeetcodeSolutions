class Solution {
public:
    int binSearch(vector<int> &nums,int target,int low,int high){
        if(low > high){
            return -1;
        }
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            return binSearch(nums,target,low,mid-1);
        }
        return binSearch(nums,target,mid+1,high);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binSearch(nums,target,0,n-1);
    }
};