class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAndVal = *max_element(nums.begin(),nums.end()), ans = 1, n = nums.size(),len = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == maxAndVal){
                len++;
                ans = max(ans, len);
            }else{
                len = 0;
            }
        }
        return ans;
    }
};