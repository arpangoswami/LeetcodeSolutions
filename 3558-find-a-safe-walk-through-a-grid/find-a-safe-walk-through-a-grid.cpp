class Solution {
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size(),cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        deque<array<int,3>> dq;
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        dq.push_front({0,0,startHealth});
        visited[0][0] = true;
        while(!dq.empty()){
            auto [sx, sy, hp] = dq.front();
            dq.pop_front();
            if(sx == (rows - 1) && sy == (cols - 1)){
                return true;
            }
            for (int k = 0; k < 4; k++) {
                int ex = sx + dx[k], ey = sy + dy[k];
                if (ex < 0 || ey < 0 || ex >= rows || ey >= cols) continue;
                
                int newHp = hp - grid[ex][ey];
                if (newHp <= 0 || visited[ex][ey]) continue;
                
                visited[ex][ey] = true;
                if (!grid[ex][ey])
                    dq.push_front({ex, ey, newHp});
                else
                    dq.push_back({ex, ey, newHp});
            }
        }
        return false;
    }
};