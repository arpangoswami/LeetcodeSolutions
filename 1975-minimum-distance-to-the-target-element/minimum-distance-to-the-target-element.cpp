class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size(), maxDist = max(n - 1 - start, start);
        if(nums[start] == target){
            return 0;
        }
        for(int i=1;i<=maxDist;i++){
            int left = (start - i) >= 0 ? nums[start - i] : -1;
            int right = (start + i) < n ? nums[start + i] : -1;
            if(left == target || right == target){
                return i;
            }
        }
        return -1;
    }
};