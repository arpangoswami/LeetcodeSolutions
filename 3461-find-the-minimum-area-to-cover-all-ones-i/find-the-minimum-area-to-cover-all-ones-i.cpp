class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int leftMost = -1,rightMost = -1,topMost = -1,bottomMost = -1;
        int rows = grid.size(), cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]){
                    if(leftMost == -1 || j < leftMost){
                        leftMost = j;
                    }
                    if(rightMost == -1 || j > rightMost){
                        rightMost = j;
                    }
                    if(topMost == -1 || i < topMost){
                        topMost = i;
                    }
                    if(bottomMost == -1 || i > bottomMost){
                        bottomMost = i;
                    }
                }
            }
            
        }
        return (bottomMost - topMost + 1) * (rightMost - leftMost + 1);
    }
};