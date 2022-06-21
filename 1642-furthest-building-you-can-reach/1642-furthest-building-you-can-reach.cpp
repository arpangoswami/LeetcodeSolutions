class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxHeap;
        int idx = 0,n = heights.size();
        for(;idx<(n-1);idx++){
            int diff = heights[idx+1] - heights[idx];
            if(diff <= 0){
                continue;
            }
            maxHeap.push(diff);
            bricks -= diff;
            if(bricks < 0){
                bricks += maxHeap.top();
                maxHeap.pop();
                ladders--;
            }
            if(ladders < 0){
                break;
            }
        }
        return idx;
    }
};