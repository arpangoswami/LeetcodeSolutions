using ar = array<int,3>;
class Solution {
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    inline bool isSafe(const int &currX, const int &currY, vector<vector<bool>> &visited, const int &rows, const int &cols){
        return (currX >= 0 && currY >= 0 && currX < rows && currY < cols && !visited[currX][currY]);
    }
    int populateHeap(const int &limit, priority_queue<ar, vector<ar>, greater<ar>> &minHeap, vector<vector<bool>> &visited, vector<vector<int>> &grid, const int &rows, const int &cols){
        if(limit < minHeap.top()[0]){
            return 0;
        }
        int ans = 0;
        while(!minHeap.empty() && limit >= minHeap.top()[0]){
            ans++;
            int currX = minHeap.top()[1], currY = minHeap.top()[2];
            minHeap.pop();
            visited[currX][currY] = true;
            for(int k=0;k<4;k++){
                int nx = currX + dx[k], ny = currY + dy[k];
                if(isSafe(nx, ny, visited, rows, cols)){
                    minHeap.push({grid[nx][ny], nx, ny});
                    visited[nx][ny] = true;
                    ans += populateHeap(limit, minHeap, visited, grid, rows, cols);
                }
            }
        }
        return ans;
    }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        set<int> distinct;
        for(vector<int> &v:grid){
            for(int &x:v){
                distinct.insert(x);
            }
        }
        priority_queue<ar, vector<ar>, greater<ar>> minHeap;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int N = distinct.size();
        vector<int> distinctElements(N);
        int ptr = 0;
        for(const int &x:distinct){
            distinctElements[ptr++] = x;
        }
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        vector<int> prefix(N);
        prefix[0] = populateHeap(distinctElements[0], minHeap, visited, grid, rows, cols);
        for(int i=1;i<N;i++){
            prefix[i] = prefix[i-1];
            prefix[i] += populateHeap(distinctElements[i], minHeap, visited, grid, rows, cols);
        }
        int ansSize = queries.size();
        vector<int> ans(ansSize);
        for(int i=0;i<ansSize;i++){
            int idx = lower_bound(distinctElements.begin(), distinctElements.end(), queries[i]) - distinctElements.begin() - 1;
            if(idx >= 0){
                ans[i] = prefix[idx];
            }
        }
        return ans;
    }
};