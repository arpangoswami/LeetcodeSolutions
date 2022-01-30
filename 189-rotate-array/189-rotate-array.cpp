class Solution {
    void reverse(vector<int> &nums,int low,int high){
        while(low < high){
            swap(nums[low++],nums[high--]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int firstPart = n - k;
        reverse(nums,0,firstPart-1);
        reverse(nums,firstPart,n-1);
        reverse(nums,0,n-1);
    }
};