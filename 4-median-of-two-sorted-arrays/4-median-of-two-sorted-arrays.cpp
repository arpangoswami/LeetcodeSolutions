class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        if(n1 > n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low = 0,high = n1;
        while(low <= high){
            int idx1 = (low+high)/2;
            int idx2 = ((n1+n2+1)/2) - idx1;
            int min1 = (idx1 == n1) ? INT_MAX : nums1[idx1];
            int max1 = (idx1 == 0) ? INT_MIN : nums1[idx1-1];
            int min2 = (idx2 == n2) ? INT_MAX : nums2[idx2];
            int max2 = (idx2 == 0) ? INT_MIN : nums2[idx2-1];
            if(max1 <= min2 && max2 <= min1){
                int num1 = max(max1,max2);
                int num2 = min(min1,min2);
                if((n1 + n2) % 2 == 0){
                    return (double(num1)+double(num2))/2.0;
                }else{
                    return num1;
                }
            }else if(max1 > min2){
                high = idx1-1;
            }else{
                low = idx1+1;
            }
        }
        return -1.00;
    }
};