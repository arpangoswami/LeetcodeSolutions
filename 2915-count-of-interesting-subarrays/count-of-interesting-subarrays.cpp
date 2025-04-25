// using ll = long long;
// class Solution {
// public:
//     long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
//         for(int &x:nums){
//             x = x%modulo;
//         }
//         unordered_map<ll,ll> prefSum;
//         prefSum[0] = -1;
//         int n = nums.size();
//         ll sum = 0;
//         for(int i=0;i<n;i++){
//             sum += nums[i];
//             sum %= modulo;
//             prefSum
//         }
//     }
// };

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count = 0, equals = 0;
        unordered_map<int, long long> mpp;
        mpp[0] = 1;

        for (int i : nums) {
            if (i % modulo == k) equals++;

            int rem = equals % modulo;
            int needed = (rem - k + modulo) % modulo;

            count += mpp[needed];
            mpp[rem]++;
        }

        return count;
    }
};