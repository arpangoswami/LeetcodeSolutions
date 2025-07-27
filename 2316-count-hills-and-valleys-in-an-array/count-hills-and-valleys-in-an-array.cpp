class Solution {
    inline bool isHill(int val, int first, int second){
        return (val > first) && (val > second);
    }
    inline bool isValley(int val, int first, int second){
        return (val < first) && (val < second);
    }
public:
    int countHillValley(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for(int i=1;i<=(n-2);){
            int prev = arr[i-1];
            int curr = arr[i];
            int nextIdx = i+1;
            while(nextIdx < n && arr[nextIdx] == curr){
                nextIdx++;
            }
            if(nextIdx < n && (isValley(curr, prev, arr[nextIdx]) || isHill(curr, prev, arr[nextIdx]))){
                ans++;
            }
            i = nextIdx;
        }
        return ans;
    }
};