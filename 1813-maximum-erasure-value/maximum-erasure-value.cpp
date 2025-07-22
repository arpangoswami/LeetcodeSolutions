class Solution {
public:
    inline int calSum(const vector<int> &prefSum,int i,int j){
        return prefSum[j] - ((i == 0) ? 0 : prefSum[i-1]);
    }
    int maximumUniqueSubarray(vector<int>& nums) {
        int lastDupIndex = -1;
        unordered_map<int,int> lastAppeared;
        vector<int> prefSum(nums.size());
        prefSum[0] = nums[0];
        for(int i=1;i<prefSum.size();i++){
            prefSum[i] = prefSum[i-1] + nums[i];
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(lastAppeared.count(nums[i])){
                lastDupIndex = max(lastDupIndex,lastAppeared[nums[i]]);
            }
            ans = max(ans,calSum(prefSum,lastDupIndex+1,i));
            lastAppeared[nums[i]] = i;
        }
        return ans;
    }
};