class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        int i=0,n = nums.size();
        for(;i<n;){
            if(nums[i] < original){
                i++;
            }else if(nums[i] == original){
                original *= 2;
                i++;
            }else{
                return original;
            }
        }
        return original;
    }
};