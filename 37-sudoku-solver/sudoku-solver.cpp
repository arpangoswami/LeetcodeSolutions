class Solution {
public:
    bool sudokuSolver(vector<vector<char>> &board,int rowNum,int colNum,vector<bitset<9>> &rows,vector<bitset<9>> &cols,vector<bitset<9>> &boxes){
        if(rowNum == 9){
            return true;
        }
        if(colNum == 9){
            return sudokuSolver(board,rowNum+1,0,rows,cols,boxes);
        }
        if(board[rowNum][colNum] != '.'){
            return sudokuSolver(board,rowNum,colNum+1,rows,cols,boxes);
        }
        for(int num=1;num<=9;num++){
            int boxNum = (rowNum/3)*3 + (colNum/3);
            if(boxes[num][boxNum] || rows[num][rowNum] || cols[num][colNum]){
                continue;
            }
            board[rowNum][colNum] = '0' + num;
            boxes[num][boxNum] = 1;
            rows[num][rowNum] = 1;
            cols[num][colNum] = 1;
            bool f = sudokuSolver(board,rowNum,colNum+1,rows,cols,boxes);
            if(f){
                return true;
            }
            board[rowNum][colNum] = '.';
            boxes[num][boxNum] = 0;
            rows[num][rowNum] = 0;
            cols[num][colNum] = 0;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> rows(10);
        vector<bitset<9>> cols(10);
        vector<bitset<9>> boxes(10);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    int boxNum = (i/3)*3 + (j/3);
                    rows[num][i] = 1;
                    cols[num][j] = 1;
                    boxes[num][boxNum] = 1;
                }
            }
        }
        sudokuSolver(board,0,0,rows,cols,boxes);
    }
};