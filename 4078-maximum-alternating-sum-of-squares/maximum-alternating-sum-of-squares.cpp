class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x,int y){
            return abs(x) < abs(y);
        });
        long long ans = 0;
        int N = nums.size();
        for(int i=N/2;i<N;i++){
            ans += (nums[i] * nums[i]);
        }
        for(int i=0;i<N/2;i++){
            ans -= (nums[i] * nums[i]);
        }
        return ans;
    }
};