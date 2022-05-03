class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1,r = -1;
        int highest = nums[0],lowest = nums[n-1];
        for(int i=1;i<n;i++){
            if(nums[i] >= highest){
                highest = nums[i];
            }else{
                r = i;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i] <= lowest){
                lowest = nums[i];
            }else{
                l = i;
            }
        }
        if(l == -1){
            return 0;
        }
        return (r-l+1);
    }
};