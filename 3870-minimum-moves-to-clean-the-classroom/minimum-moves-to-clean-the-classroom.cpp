class Solution {
    constexpr static int dx[4] = {-1,0,0,1};
    constexpr static int dy[4] = {0,-1,1,0};
public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size(), cols = classroom[0].size(), startRow = 0, startCol = 0, k = 0;
        vector<vector<int>> id(rows, vector<int>(cols, -1));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(classroom[i][j] == 'S'){
                    startRow = i;
                    startCol = j;
                }else if(classroom[i][j] == 'L'){
                    id[i][j] = k;
                    k++;
                }
            }
        }
        int full = (1 << k) - 1;
        if(!full){
            return 0;
        }
        vector<int> best(rows * cols * (full + 1), -1);
        auto key = [&](int r,int c,int mk){
            return (r * cols + c) * (full + 1) + mk;
        };
        queue<array<int,4>> q;
        best[key(startRow, startCol, 0)] = energy;
        q.push({startRow, startCol, 0, energy});
        for(int moves = 0;!q.empty(); moves++){
            for(int sz = q.size();sz--;){
                auto [row, col, mask, e] = q.front();
                q.pop();
                if(e == 0){
                    continue;
                }
                for(int d=0;d<4;d++){
                    int newRow = row+dx[d],newCol = col+dy[d];
                    if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols){
                        continue;
                    }
                    char ch = classroom[newRow][newCol];
                    if(ch == 'X'){
                        continue;
                    }
                    int newMask = mask | (id[newRow][newCol] >= 0 ? 1 << id[newRow][newCol] : 0);
                    if(newMask == full){
                        return moves+1;
                    }
                    int newEnergy = (ch == 'R') ? energy : e - 1;
                    int &b = best[key(newRow, newCol, newMask)];
                    if(newEnergy > b){
                        b = newEnergy;
                        q.push({newRow, newCol, newMask, b});
                    }
                }
            }
        }
        return -1;
    }
};