class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int lIdx = -1;
        for(int i=n-1;i>=1;i--){
            if(nums[i] > nums[i-1]){
                lIdx = i;
                break;
            }
        }
        if(lIdx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        lIdx--;
        int rIdx = -1;
        for(int i=n-1;i>lIdx;i--){
            if(nums[i] > nums[lIdx]){
                rIdx = i;
                break;
            }
        }
        swap(nums[lIdx],nums[rIdx]);
        reverse(nums.begin()+lIdx+1,nums.end());
    }
};