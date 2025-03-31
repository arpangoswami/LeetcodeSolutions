class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        long long maxSum = 0L, minSum = 0L;
        int N = v.size();
        for(int i = 0; i < N-1; i++){
            int pairWise = v[i] + v[i+1];
            maxSum += pairWise;
            minSum += pairWise;
            maxHeap.push(v[i]+v[i+1]);
            minHeap.push(v[i]+v[i+1]);
            if(maxHeap.size() >= k){
                long long maxPairSum = maxHeap.top();
                long long minPairSum = minHeap.top();
                maxSum -= maxPairSum;
                minSum -= minPairSum;
                maxHeap.pop();
                minHeap.pop();
            }
        }
        return minSum-maxSum;
    }
};