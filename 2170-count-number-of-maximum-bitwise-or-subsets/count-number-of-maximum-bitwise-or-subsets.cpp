class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int x:nums){
            maxOr |= x;
        }
        int ans = 0,n = nums.size();
        for(int i=1;i<(1 << n);i++){
            int currOr = 0;
            for(int j=0;j<n;j++){
                if((i >> j) & 1){
                    currOr |= nums[j];
                }
            }
            if(currOr == maxOr){
                ans++;
            }
        }
        return ans;
    }
};