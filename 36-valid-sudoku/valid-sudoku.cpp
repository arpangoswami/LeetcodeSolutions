class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,set<char>> row,col,box;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    int bxNo = (i/3)*3 + (j/3);
                    if(row[i].count(c)){
                        return false;
                    }
                    if(col[j].count(c)){
                        return false;
                    }
                    if(box[bxNo].count(c)){
                        return false;
                    }
                    row[i].insert(c);
                    col[j].insert(c);
                    box[bxNo].insert(c);
                }
            }
        }
        return true;
    }
};