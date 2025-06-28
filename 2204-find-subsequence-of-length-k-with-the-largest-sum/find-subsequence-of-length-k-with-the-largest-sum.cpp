using pii = pair<int,int>;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pii,vector<pii>,greater<pii>> minHeap;
        int N = nums.size();
        for(int i=0;i<N;i++){
            if(minHeap.size() < k){
                minHeap.push({nums[i], i});
            }else if(nums[i] > minHeap.top().first){
                minHeap.pop();
                minHeap.push({nums[i], i});
            }
        }
        const int INVALID_VALUE = 1e9;
        vector<int> placeHolder(N, INVALID_VALUE);
        while(!minHeap.empty()){
            pii top = minHeap.top();
            minHeap.pop();
            placeHolder[top.second] = top.first;
        }
        vector<int> ans(k);
        int ptr = 0;
        for(int i=0;i<N;i++){
            if(placeHolder[i] != INVALID_VALUE){
                ans[ptr++] = placeHolder[i];
            }
        }
        return ans;
    }
};