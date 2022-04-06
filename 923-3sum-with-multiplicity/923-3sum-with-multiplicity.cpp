const int mod = 1e9 + 7;
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int> twoSum;
        int n = arr.size(),ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans%mod + twoSum[target - arr[i]]%mod) % mod;
            for(int j=0;j<i;j++){
                twoSum[arr[j] + arr[i]]++;
            }
        }
        return ans;
    }
};