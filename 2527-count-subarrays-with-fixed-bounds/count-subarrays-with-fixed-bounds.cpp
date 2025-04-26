typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans = 0, leftBound = -1,leftMin = -1,leftMax = -1,n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                leftMin = (nums[i] == minK ? i : leftMin);
                leftMax = (nums[i] == maxK ? i : leftMax);
                ans += max(0LL, min(leftMin,leftMax) - leftBound);
            }else{
                leftBound = i;
                leftMin = -1;
                leftMax = -1;
            }
        }
        return ans;
    }
};