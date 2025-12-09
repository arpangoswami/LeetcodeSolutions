class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int maxm = *max_element(nums.begin(), nums.end());
        vector<int> freqMap1(maxm+1), freqMap2(maxm+1);
        for(int x:nums){
            freqMap1[x]++;
        }
        int ans = 0,n = nums.size();
        const int MOD = 1e9 + 7;
        freqMap2[nums[0]]++;
        freqMap1[nums[0]]--;
        for(int i=1;i<(n-1);i++){
            freqMap1[nums[i]]--;
            int twice = nums[i] * 2;
            if(twice <= maxm){
                ans += (static_cast<long long>(freqMap1[twice]) * freqMap2[twice]) % MOD;
                ans %= MOD;
            }
            freqMap2[nums[i]]++;
        }
        return ans;
    }
};