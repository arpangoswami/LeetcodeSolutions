class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int n = nums.size();
        multiset<int> windowElements;
        int ans = 1;
        for(int i=0;i<n;i++){
            windowElements.insert(nums[i]);
            while(left <= i && (*windowElements.rbegin() - *windowElements.begin()) > limit){
                auto it = windowElements.find(nums[left]);
                windowElements.erase(it);
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};