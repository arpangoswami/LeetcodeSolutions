class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        int m = matrix.size(),n = matrix[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=matrix[0][i];
        }
        for(int i=1;i<m;i++){
            ans+=matrix[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 1+min({matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]});
                    ans+=matrix[i][j];
                }
            }
        }
        return ans;
    }
};