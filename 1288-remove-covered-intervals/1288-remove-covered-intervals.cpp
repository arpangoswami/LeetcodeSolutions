class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &v1,vector<int> &v2){
           if(v1[0] == v2[0]){
               return v1[1] > v2[1];
           } 
            return v1[0] < v2[0];
        });
        int ans = 1;
        int last = intervals[0][1];
        int N = intervals.size();
        if(N == 0){
            return 0;
        }
        for(int i=1;i<N;i++){
            if(intervals[i][1] <= last){
                continue;
            }
            ans++;
            last = intervals[i][1];
        }
        return ans;
    }
};