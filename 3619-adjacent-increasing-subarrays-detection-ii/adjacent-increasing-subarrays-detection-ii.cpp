auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int curr = 1,prev = nums[0],prevCurr = 0,ans = 1,n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] > prev){
                curr++;
            }else{
                ans = max(ans, min(prevCurr, curr));
                ans = max(ans, curr/2);
                prevCurr = curr;
                curr = 1;
            }
            prev = nums[i];
        }
        ans = max(ans, min(prevCurr, curr));
        ans = max(ans, curr/2);
        return ans;
    }
};