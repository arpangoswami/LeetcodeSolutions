class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxm = *max_element(nums.begin(), nums.end());
        int minm = *min_element(nums.begin(), nums.end());
        int maxIdx = -1, minIdx = -1,n = nums.size();
        if(n == 1){
            return 1;
        }
        for(int i=0;i<n;i++){
            if(nums[i] == maxm){
                maxIdx = i;
            }else if(nums[i] == minm){
                minIdx = i;
            }
        }
        int greaterIdx = max(maxIdx, minIdx), smallIdx = min(maxIdx, minIdx);
        int ans = min(n - smallIdx, greaterIdx+1);
        ans = min(ans, smallIdx+1 + n - greaterIdx);
        return ans;
    }
};