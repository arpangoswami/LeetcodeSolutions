class Solution {
    int recSolve(int idx1,int idx2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0) {
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        return dp[idx1][idx2] = max({
            recSolve(idx1-1,idx2,nums1,nums2,dp),
            recSolve(idx1,idx2-1,nums1,nums2,dp),
            recSolve(idx1-1,idx2-1,nums1,nums2,dp) + nums1[idx1] * nums2[idx2]
            });
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int maxm1 = *max_element(nums1.begin(),nums1.end()), maxm2 = *max_element(nums2.begin(), nums2.end()), minm1 = *min_element(nums1.begin(),nums1.end()),minm2 = *min_element(nums2.begin(), nums2.end());
        if(maxm1 < 0 && minm2 > 0){
            return maxm1*minm2;
        }
        else if(maxm2 < 0 && minm1 > 0){
            return maxm2*minm1;
        }
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recSolve(m-1,n-1,nums1,nums2,dp);
    }
};