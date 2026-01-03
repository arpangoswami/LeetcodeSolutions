class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // only one element is repeated, hence if repeat amongst first 3 elements seen that is the repeated element
        if(nums[0] == nums[1]){
            return nums[0];
        }
        if(nums[0] == nums[2] || nums[1] == nums[2]){
            return nums[2];
        }
        // if no repeated elements seen, since one number appears half the number of times originally and has only occured at max once in the first three elements hence must be in majority in the remaining n-3 elements. Hence Boyer Moore's voting algorithm works
        int n = nums.size();
        int majority = nums[3], freq = 1;
        for(int i=4;i<n;i++){
            if(nums[i] == majority){
                freq++;
            }else{
                freq--;
                if(freq < 0){
                    majority = nums[i];
                    freq = 1;
                }
            }
        }
        return majority;
    }
};