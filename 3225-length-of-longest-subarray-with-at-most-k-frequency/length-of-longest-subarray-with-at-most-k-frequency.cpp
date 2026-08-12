class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        int n = nums.size(), ans = 0;
        for(int left=0,right=0;right < n;right++){
            freqMap[nums[right]]++;
            while(left <= right && freqMap[nums[right]] > k){
                freqMap[nums[left]]--;
                left++;
            }
            ans = max(ans,right - left + 1);
        }
        return ans;
    }
};