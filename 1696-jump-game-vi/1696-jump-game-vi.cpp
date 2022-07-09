class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        dq.push_back(0);
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[dq.front()];
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            while(!dq.empty() && (i-k)>=dq.front()){
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return nums[n-1];
    }
};