class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int N = nums.size();
        int minTillNow = nums[0], ans = -1;
        for(int i=1;i<N;i++){
            if(nums[i] > minTillNow){
                ans = max(ans, nums[i] - minTillNow);
            }
            minTillNow = min(minTillNow, nums[i]);
        }
        return ans;
    }
};