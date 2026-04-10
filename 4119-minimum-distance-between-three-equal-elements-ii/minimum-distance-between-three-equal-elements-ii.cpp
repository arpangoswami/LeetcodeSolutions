class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> idx(n+1);
        for(int i=0;i<n;i++){
            idx[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for(int i=1;i<=n;i++){
            if(idx[i].size() < 3){
                continue;
            }
            for(int j=0;j<(idx[i].size()-2);j++){
                ans = min(ans, 2*idx[i][j+2] - 2*idx[i][j]);
            }
        }
        return (ans == 1e9) ? -1 : ans;
    }
};