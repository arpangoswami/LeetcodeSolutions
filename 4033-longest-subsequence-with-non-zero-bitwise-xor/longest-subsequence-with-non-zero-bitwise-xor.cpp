class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cumXor = 0;
        for(int x:nums){
            cumXor ^= x;
        }
        if(cumXor != 0){
            return (int)nums.size();
        }
        int nonZeroCount = nums.size() - count(nums.begin(), nums.end(), 0);
        if(nonZeroCount != 0){
            return (int)nums.size() - 1;
        }
        return 0;
    }
};