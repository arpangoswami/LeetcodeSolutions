class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0){
            return {};
        }
        sort(intervals.begin(),intervals.end(),[](auto &x,auto &y){
            return x[0] < y[0];
        });
        vector<vector<int>> ans{intervals[0]};
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};