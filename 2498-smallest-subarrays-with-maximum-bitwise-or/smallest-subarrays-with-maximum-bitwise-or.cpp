class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<vector<int>> bitSize(31);
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=30;j++){
                if((nums[i] >> j) & 1){
                    bitSize[j].push_back(i);
                }
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int maxIdx = i;
            for(int j=0;j<=30;j++){
                if(bitSize[j].size() > 0){
                    maxIdx = max(maxIdx,bitSize[j].back());
                }
            }
            ans[i] = maxIdx - i + 1;
            for(int j=0;j<=30;j++){
                if(bitSize[j].size() > 0 && bitSize[j].back() == i){
                    bitSize[j].pop_back();
                }
            }
        }
        return ans;
    }
};