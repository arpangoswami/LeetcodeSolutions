class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int curr = 1,maxSeq = 1,n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                curr++;
                maxSeq = max(maxSeq,curr);
            }else{
                curr = 1;
            }
        }
        curr = 1;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                curr++;
                maxSeq = max(maxSeq, curr);
            }else{
                curr = 1;
            }
        }
        return maxSeq;
    }
};