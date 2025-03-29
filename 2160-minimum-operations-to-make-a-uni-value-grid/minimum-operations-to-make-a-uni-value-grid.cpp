class Solution {
    int getMinOperations(vector<int> &numbers, int mid, int stepSize){
        int n = numbers.size();
        int ans = 0;
        for(int i=0;i<=mid;i++){
            ans += (numbers[mid] - numbers[i])/stepSize;
        }
        for(int i=mid+1;i<n;i++){
            ans += (numbers[i] - numbers[mid])/stepSize;
        }
        return ans;
    }
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> numbers(rows*cols);
        int ptr = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                numbers[ptr++] = grid[i][j];
            }
        }
        sort(numbers.begin(), numbers.end());
        int n = numbers.size();
        for(int i=1;i<n;i++){
            if((numbers[i] - numbers[0])%x != 0){
                return -1;
            }
        }
        if((rows*cols)%2 == 0){
            int firstMid = (n-1)/2 , secondMid = n/2;
            return min(getMinOperations(numbers, firstMid, x), getMinOperations(numbers, secondMid, x));
        }
        int mid = n/2;
        return getMinOperations(numbers, mid, x);
    }
};