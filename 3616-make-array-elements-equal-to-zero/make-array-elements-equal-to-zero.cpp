class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int suffSum = totalSum, prefSum = 0, ans = 0;
        for(int &x:nums){
            suffSum -= x;
            prefSum += x;
            if(x == 0){
                if(suffSum == prefSum){
                    ans += 2;
                }else if((suffSum == prefSum + 1) || (prefSum == suffSum + 1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};