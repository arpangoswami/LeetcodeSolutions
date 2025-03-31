class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int N = v.size();
        for(int i = 0; i < N-1; i++){
            maxHeap.push(v[i]+v[i+1]);
            minHeap.push(v[i]+v[i+1]);
            if(maxHeap.size() >= k){
                maxHeap.pop();
                minHeap.pop();
            }
        }
        long long int ans1 = 0, ans2 = 0;
        while(!maxHeap.empty()){
            ans1 += maxHeap.top();
            ans2 += minHeap.top();
            maxHeap.pop();
            minHeap.pop();
        }
        return ans2-ans1;
    }
};