class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        for(int i=1;i*i<=N;i++){
            if((N % i) == 0){
                ans += (nums[i - 1] * nums[i - 1]);
                    int otherVal = N / i;
                    if(otherVal != i){
                        ans += (nums[otherVal - 1] * nums[otherVal - 1]);
                    }
            }
        }
        return ans;
    }
};