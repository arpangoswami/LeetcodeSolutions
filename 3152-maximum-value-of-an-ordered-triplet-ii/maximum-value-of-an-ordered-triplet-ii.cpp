using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll leftMost = nums[0], maxDifference = max(0LL, (ll)nums[0] - nums[1]), ans = maxDifference*nums[2];
        for(int i=3;i<n;i++){
            leftMost = max(leftMost, (ll)nums[i-2]);
            maxDifference = max(maxDifference, leftMost - (ll)nums[i-1]);
            ans = max(ans, maxDifference * (ll)nums[i]);
        }
        return ans;
    }
};