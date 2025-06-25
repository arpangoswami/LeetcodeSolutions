// using ll = long long;
// class Solution {
//     bool check(ll mid, vector<int> &nums1, vector<int> &nums2, long long k){
//         ll prods = 0;
//         for(int &x:nums1){
//             int toFind = mid/x;
//             int idx = lower_bound(nums2.begin(), nums2.end(), toFind) - nums2.begin();
//             prods += (idx+1);
//             if(prods >= k){
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
//         ll minm = (ll)nums1[0]*(ll)nums2[0];
//         ll maxm = (ll)nums1.back()*(ll)nums2.back();
//         ll ans = maxm, low = minm, high = maxm;
//         while(low <= high){
//             ll mid = (low + high)/2;
//             if(check(mid, nums1, nums2, k)){
//                 ans = mid;
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return maxm;
//     }
// };

class Solution {
public:
    int f(vector<int>& nums2, long long x1, long long v) {
        int n2 = nums2.size();
        int left = 0, right = n2 - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x1 >= 0 && nums2[mid] * x1 <= v ||
                x1 < 0 && nums2[mid] * x1 > v) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (x1 >= 0) {
            return left;
        } else {
            return n2 - left;
        }
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size();
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;
            for (int i = 0; i < n1; i++) {
                count += f(nums2, nums1[i], mid);
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};