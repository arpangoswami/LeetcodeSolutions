class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0){
            return n;
        }
        sort(points.begin(),points.end(),[](vector<int> &v1,vector<int> &v2){
            return v1[1] < v2[1];
        });
        int ans = 1;
        int last = points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0] <= last){
                continue;
            }
            ans++;
            last = points[i][1];
        }
        return ans;
    }
};