class Solution {
    int getVal(char ch){
        if(ch == 'X'){
            return 1;
        }else if(ch == 'Y'){
            return -1;
        }
        return 0;
    }
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> pref(rows, vector<int> (cols));
        vector<vector<bool>> present(rows, vector<bool> (cols));
        pref[0][0] = getVal(grid[0][0]);
        present[0][0] = getVal(grid[0][0]);
        int ans = 0;
        for(int i=1;i<rows;i++){
            pref[i][0] += (pref[i-1][0] + getVal(grid[i][0]));
            present[i][0] = (getVal(grid[i][0]) | present[i-1][0]);
            if((pref[i][0] == 0) && present[i][0]){
                ans++;
            }
            
        }
        for(int j=1;j<cols;j++){
            pref[0][j] += (pref[0][j-1] + getVal(grid[0][j]));
            present[0][j] = (getVal(grid[0][j]) | present[0][j-1]);
            if((pref[0][j] == 0) && present[0][j]){
                ans++;
            }
            
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                pref[i][j] += (pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + getVal(grid[i][j]));
                present[i][j] = (getVal(grid[i][j]) | present[i][j-1] | present[i-1][j]);
                if((pref[i][j] == 0) && present[i][j]){
                    ans++;
                }
                
            }
        }
        return ans;
    }
};