class Solution {
public:
constexpr static int MOD = 1e9+7;
        int solve(int idx,int g1,int g2,vector<int> &nums,vector<vector<vector<int>>> &dp){
            if(idx == nums.size()){
                return (g1 != 0 && g1 == g2);
            }
            int &ans = dp[idx][g1][g2];
            if(ans != -1){
                return ans;
            }
            ans = solve(idx+1,g1,g2,nums,dp);
            ans += solve(idx+1, g1 == 0 ? nums[idx] : __gcd(g1, nums[idx]), g2, nums,dp);
            ans %= MOD;
            ans += solve(idx+1, g1, g2 == 0 ? nums[idx] : __gcd(g2, nums[idx]), nums,dp);
            ans %= MOD;
            return ans;
        }
    int subsequencePairCount(vector<int>& nums) {
            int n = nums.size();
            int maxm = *max_element(nums.begin(), nums.end());
            vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(maxm+1, vector<int> (maxm+1, -1)));
            return solve(0, 0, 0, nums, dp);
        }
};