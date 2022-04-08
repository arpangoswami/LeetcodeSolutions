class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int currSum1 = 0,currSum2 = 0;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            currSum1 += (nums1[i]*nums2[n-i-1]);
            currSum2 += (nums2[i]*nums1[n-i-1]);
        }
        return min(currSum1,currSum2);
    }
};