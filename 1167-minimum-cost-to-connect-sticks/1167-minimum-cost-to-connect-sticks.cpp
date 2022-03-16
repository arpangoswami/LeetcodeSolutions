class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>> pq(sticks.begin(),sticks.end());
        int ans = 0;
        while(pq.size() > 1){
            int val1 = pq.top();
            pq.pop();
            int val2 = pq.top();
            pq.pop();
            ans += (val1+val2);
            pq.push(val1+val2);
        }
        return ans;
    }
};