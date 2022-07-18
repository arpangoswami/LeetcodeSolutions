class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),cols = matrix[0].size();
        int ans = 0;
        for(int start = 0;start<rows;start++){
            for(int end=start;end<rows;end++){
                unordered_map<int,int>mp;
                int sum = 0;
                mp[0]++;
                for(int j=0;j<cols;j++){
                    sum += matrix[start][j];
                    if(mp[sum-target]) ans += mp[sum-target];
                    mp[sum]++;
                    if(end < rows-1) matrix[start][j] += matrix[end+1][j];
                }
            }
        }
        return ans;
    }
};