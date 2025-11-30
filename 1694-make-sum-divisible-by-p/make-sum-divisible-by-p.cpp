using ll = long long;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ll totalSum = accumulate(nums.begin(), nums.end(), 0L);
        ll toRemove = totalSum % p;
        if(toRemove == 0){
            return 0;
        }
        unordered_map<ll,int> lastIdx;
        lastIdx[0] = -1;
        ll runningSum = 0L;
        int N = nums.size(), ans = N;
        for(int i=0;i<N;i++){
            runningSum += nums[i];
            runningSum %= p;

            int wrapAround = (runningSum - toRemove + p) % p;

            if(lastIdx.count(wrapAround)){
                ans = min(ans, i - lastIdx[wrapAround]);
            }

            lastIdx[runningSum] = i;
        }

        return ans == N ? -1 : ans;
    }
};

static const int init = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();