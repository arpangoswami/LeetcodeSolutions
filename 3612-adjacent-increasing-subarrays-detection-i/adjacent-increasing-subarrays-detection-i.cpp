class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prevWindow = 0,currWindow = 1,prev = nums[0], n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] > prev){
                currWindow++;
            }else{
                if((prevWindow >= k && currWindow >= k) || (currWindow >= 2*k)){
                    return true;
                }
                prevWindow = currWindow;
                currWindow = 1;
            }
            prev = nums[i];
        }
        if((prevWindow >= k && currWindow >= k) || (currWindow >= 2*k)){
            return true;
        }
        return false;
    }
};