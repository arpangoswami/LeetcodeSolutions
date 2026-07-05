class Solution {
    constexpr static int MOD = 1e9+7;
    vector<vector<int>> dpMaxScore(const int &rows,const int &cols,const vector<string> &board){
        vector<vector<int>> dp(rows, vector<int>(cols));
        dp[rows-1][cols-1] = 0;
        for(int j=cols-2;j>=0;j--){
            if(board[rows-1][j] == 'X' || dp[rows-1][j+1] == -1){
                dp[rows-1][j] = -1;
            }else{
                dp[rows-1][j] = (board[rows-1][j] - '0') + dp[rows-1][j+1];
            }
        }
        for(int i=rows-2;i>=0;i--){
            if(board[i][cols-1] == 'X' || dp[i+1][cols-1] == -1){
                dp[i][cols-1] = -1;
            }else{
                dp[i][cols-1] = (board[i][cols-1] - '0') + dp[i+1][cols-1];
            }
        }
        for(int i=rows-2;i>=0;i--){
            for(int j=cols-2;j>=0;j--){
                int best = -1;
                for (int val : {dp[i+1][j], dp[i][j+1], dp[i+1][j+1]}) {
                    if (val != -1) best = max(best, val);
                }
                if (board[i][j] == 'X' || best == -1) {
                    dp[i][j] = -1;
                } else if (isdigit(board[i][j])) {
                    dp[i][j] = (board[i][j] - '0') + best;
                } else {
                    dp[i][j] = best;
                }
            }
        }
        return dp;
    }
    int dpTotalWays(const int &rows,const int &cols,const vector<string> &board,const vector<vector<int>> &score){
        vector<vector<long long>> ways(rows, vector<long long>(cols, 0));
        ways[rows-1][cols-1] = 1;
        for (int j = cols-2; j >= 0; j--) {
            if (score[rows-1][j] == -1) continue;
            ways[rows-1][j] = ways[rows-1][j+1];
        }
        for (int i = rows-2; i >= 0; i--) {
            if (score[i][cols-1] == -1) continue;
            ways[i][cols-1] = ways[i+1][cols-1];
        }
        for (int i = rows-2; i >= 0; i--) {
            for (int j = cols-2; j >= 0; j--) {
                if (score[i][j] == -1) continue;
                int cellVal = isdigit(board[i][j]) ? board[i][j]-'0' : 0;
                int best = score[i][j] - cellVal;
                for (auto [ni, nj] : vector<pair<int,int>>{{i+1,j},{i,j+1},{i+1,j+1}}) {
                    if (score[ni][nj] == best)
                        ways[i][j] = (ways[i][j] + ways[ni][nj]) % MOD;
                }
            }
        }
        return (int)ways[0][0];
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> dpNumWays(rows,vector<int>(cols,-1));
        vector<vector<int>> sol = dpMaxScore(rows, cols, board);
        if(sol[0][0] < 0){
            return {0,0};
        }
        int ways = dpTotalWays(rows,cols,board,sol);
        return {sol[0][0], ways};
    }
};