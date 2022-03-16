class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-k)%(k-1) != 0){
            return -1;
        }
        vector<int> prefSum(n);
        prefSum[0] = stones[0];
        for(int i=1;i<n;i++){
            prefSum[i] = prefSum[i-1] + stones[i];
        }
        auto calSum = [&](int x,int y){
            int ans = prefSum[y];
            if(x > 0){
                ans -= prefSum[x-1];
            }
            return ans;
        };
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int length=1;length<=n;length++){
            for(int row=0;row<=(n-length);row++){
                int col = row+length-1;
                if(length < k){
                    dp[row][col] = 0;
                }else if(length == k){
                    dp[row][col] = calSum(row,col);
                }else{
                    dp[row][col] = 1e9;
                    for(int mid=row;mid<col;mid+=(k-1)){
                        dp[row][col] = min(dp[row][col],dp[row][mid]+dp[mid+1][col]);
                    }
                    if((length - k)%(k-1) == 0){
                        dp[row][col] += calSum(row,col);
                    }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[0][n-1];
    }
};