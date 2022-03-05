class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int maxm = *max_element(nums.begin(),nums.end());
        vector<int> freq(maxm+1);
        for(int x:nums){
            freq[x]++;
        }
        int lastPicked = freq[1],lastNotPicked = 0;
        for(int i=2;i<=maxm;i++){
            int temp = lastPicked;
            lastPicked = max(lastNotPicked+i*freq[i],lastPicked);
            lastNotPicked = temp;
        }
        return lastPicked;
    }
};