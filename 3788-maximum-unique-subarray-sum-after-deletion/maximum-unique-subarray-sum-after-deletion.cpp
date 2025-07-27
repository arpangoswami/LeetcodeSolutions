class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxm = *max_element(nums.begin(),nums.end());
        if(maxm < 0){
            return maxm;
        }
        vector<bool> taken(101);
        int ans = 0;
        for(int &x:nums){
            if(x < 0 || taken[x]){
                continue;
            }
            ans += x;
            taken[x] = true;
        }
        return ans;
    }
};