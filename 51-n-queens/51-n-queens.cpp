class Solution {
public:
    bool backtrack(vector<string> &board,vector<vector<string>> &sol,int row,vector<bool> &diag1,vector<bool> &diag2,vector<bool> &column,int n){
        if(row == n){
            sol.push_back(board);
            return false;
        }
        for(int j=0;j<n;j++){
            if(!column[j] && !diag1[row + j] && !diag2[row - j + (n-1)]){
                column[j] = true;
                diag1[row+j] = true;
                diag2[row - j + (n-1)] = true;
                board[row][j] = 'Q';
                backtrack(board,sol,row+1,diag1,diag2,column,n);
                column[j] = false;
                diag1[row+j] = false;
                diag2[row - j + (n-1)] = false;
                board[row][j] = '.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> diag1(2*n-1);
        vector<bool> diag2(2*n-1);
        vector<bool> col(n);
        vector<vector<string>> sol;
        vector<string> board(n);
        for(int i=0;i<n;i++){
            string s;
            for(int j=0;j<n;j++){
                s.push_back('.');
            }
            board[i] = s;
        }
        // for(int i=0;i<n;i++){
        //     cout<<board[i]<<"\n";
        // }
        backtrack(board,sol,0,diag1,diag2,col,n);
        return sol;
    }
};