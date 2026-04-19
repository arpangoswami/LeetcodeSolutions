class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, ans = 0;
        for(;i<nums1.size() && j<nums2.size();j++){
            if(nums2[j] >= nums1[i]){
                ans = max(ans, j - i);
            }else{
                i++;
            }
        }
        return ans;
    }
};