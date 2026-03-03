class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeroes(n);
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]!=0){
                    break;
                }
                count++;
            }
            trailingZeroes[i] = count;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int zerosRequired = (n - i - 1);
            int j = i;
            for(j=i;j<n;j++){
                if(trailingZeroes[j] >= zerosRequired){
                    break;
                }
            }
            if(j == n){
                return -1;
            }
            ans += (j - i);
            for(int k=j;k>i;k--){
                swap(trailingZeroes[k], trailingZeroes[k-1]);
            }
        }
        return ans;
    }
};