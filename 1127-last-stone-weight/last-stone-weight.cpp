class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size() > 1){
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            int diff = num1-num2;
            if(diff > 0){
                pq.push(diff);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};