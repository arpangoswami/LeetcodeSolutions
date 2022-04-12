class Solution {
    bool isAlive(int x,int y,int m,int n,vector<vector<int>> &board){
        return ((x >= 0) && (y >= 0) && (x < m) && (y < n) && (board[x][y] == 1 || board[x][y] == -1));
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        int m = board.size(),n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 0){
                    int liveNeighbours = 0;
                    for(int k=0;k<8;k++){
                        int nx = i+dx[k],ny=j+dy[k];
                        if(isAlive(nx,ny,m,n,board)){
                            liveNeighbours++;
                        }
                    }   
                    if(liveNeighbours == 3){
                        board[i][j] = 2;
                    }
                    //cout<<"i: "<<i<<" j: "<<j<<" liveNieghbours: "<<liveNeighbours<<"\n";
                }else{
                    int liveNeighbours = 0;
                    for(int k=0;k<8;k++){
                        int nx = i+dx[k],ny=j+dy[k];
                        if(isAlive(nx,ny,m,n,board)){
                            liveNeighbours++;
                        }
                    }
                    if(liveNeighbours > 3 || liveNeighbours < 2){
                        board[i][j] = -1;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == -1){
                    board[i][j] = 0;
                }else if(board[i][j] == 2){
                    board[i][j] = 1;
                }
            }
        }
    }
};