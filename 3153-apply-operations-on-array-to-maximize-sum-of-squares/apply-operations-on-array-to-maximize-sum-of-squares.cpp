class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(30);
        for(int x:nums){
            for(int i=0;i<30;i++){
                if((x >> i) & 1){
                    bits[i]++;
                }
            }
        }
        long long ans = 0;
        const int MOD = 1e9 + 7;
        for(int i=0;i<k;i++){
            long long num = 0;
            for(int i=0;i<30;i++){
                if(bits[i] > 0){
                    bits[i]--;
                    num |= (1 << i);
                }
            }
            ans += ((num * num) % MOD);
            ans %= MOD;
        }
        return ans;
    }
};