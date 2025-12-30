class Solution {
    constexpr static int dx[8][3][2] = {{{-1,-1}, {-1,0}, {-1,1}}, 
    {{0,-1}, {0,0}, {0,1}}, 
    {{1,-1}, {1,0}, {1,1}}, 
    {{-1,-1}, {0,-1}, {1,-1}}, 
    {{-1,0}, {0,0}, {1,0}}, 
    {{-1,1}, {0,1}, {1,1}}, 
    {{-1,-1}, {0,0}, {1,1}}, 
    {{-1,1}, {0,0}, {1,-1}}};
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;
        for(int i=1;i<(rows-1);i++){
            for(int j=1;j<(cols-1);j++){
                bool flag = true;
                vector<bool> visited(9);
                for(int k=0;k<8;k++){
                    int sum = 0;
                    for(int l=0;l<3;l++){
                        int num = grid[i+dx[k][l][0]][j+dx[k][l][1]];
                        sum += num;
                        if (num < 1 || num > 9){
                            flag = false;
                            break;
                        }
                        visited[num-1] = true;
                    }
                    if(sum != 15){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    int cnt = count(visited.begin(), visited.end(), false);
                    if(cnt == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};