class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long ans = accumulate(nums.begin(), nums.end(), 0LL) - ((long long)nums.size() * *min_element(nums.begin(), nums.end()));
        return ans;
    }
};