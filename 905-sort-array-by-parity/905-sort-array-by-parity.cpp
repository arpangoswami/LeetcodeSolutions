class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i=0,j = (int)nums.size()-1;i<j;i++){
            while(j > i && nums[j] & 1){
                j--;
            }
            if(nums[i] & 1){
                swap(nums[i],nums[j]);
                j--;
            }
        }
        return nums;
    }
};