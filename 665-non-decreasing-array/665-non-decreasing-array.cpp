class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int atMax = 0,n = nums.size(),idx = -1;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                atMax++;
                if(atMax == 2){
                    return false;
                }
                if(i < 2 || nums[i-2] <= nums[i]){
                    nums[i-1] = nums[i];
                }else {
                    nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }
};