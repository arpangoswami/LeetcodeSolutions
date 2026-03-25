using ll = long long;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll totalSum = 0;
        int rows = grid.size(), cols = grid[0].size();
        for(int i=0;i<rows;i++){
            totalSum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }
        if(totalSum % 2 != 0){
            return false;
        }
        ll currSum = 0;
        for(int i=0;i<rows;i++){
            currSum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
            if(currSum * 2 == totalSum){
                return true;
            }
        }
        currSum = 0;
        for(int j=0;j<cols;j++){
            for(int i=0;i<rows;i++){
                currSum += grid[i][j];
            }
            if(currSum * 2 == totalSum){
                return true;
            }
        }
        return false;
    }
};