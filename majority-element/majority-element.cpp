class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return -1;
        }
        int ans = nums[0],counter = 1;
        for(int i=1;i<n;i++){
            if(nums[i] == ans){
                counter++;
            }else{
                counter--;
                if(counter == 0){
                    counter = 1;
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
};