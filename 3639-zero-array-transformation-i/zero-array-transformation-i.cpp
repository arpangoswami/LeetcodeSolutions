class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefSum(n);
        for(vector<int> &v:queries){
            prefSum[v[0]]++;
            int lastIdx = v[1];
            if(lastIdx < (n-1)){
                prefSum[lastIdx+1]--;
            }
        }
        for(int i=1;i<n;i++){
            prefSum[i] += prefSum[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i] > prefSum[i]){
                return false;
            }
        }
        return true;
    }
};