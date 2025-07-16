class Solution {
    int sameRemainder(vector<int> &nums, int rem){
        int ans = 0;
        for(int &x:nums){
            if((x & 1) == rem){
                ans++;
            }
        }
        return ans;
    }
    int alternateRemainder(vector<int> &nums, int rem){
        int ans = 0;
        for(int &x:nums){
            if((x & 1) == rem){
                ans++;
                rem ^= 1;
            }
        }
        return ans;
    }
public:
    int maximumLength(vector<int>& nums) {
        return max({sameRemainder(nums, 0), sameRemainder(nums, 1), alternateRemainder(nums, (nums[0] & 1))});
    }
};