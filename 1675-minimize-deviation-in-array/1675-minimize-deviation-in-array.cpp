class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        for(int &x:nums){
            if(x & 1){
                x *= 2;
            }
        }
        int minimum = *min_element(nums.begin(),nums.end());
        priority_queue<int> pq(nums.begin(),nums.end());
        int ans = pq.top() - minimum;
        while(pq.top() % 2 == 0){
            int maximum = pq.top();
            pq.pop();
            if(maximum % 2 == 0){
                maximum /= 2;
                minimum = min(minimum,maximum);
                pq.push(maximum);
            }
            ans = min(ans,pq.top()-minimum);
        }
        return ans;
    }
};