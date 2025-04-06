class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>solution;
        if(nums.size() == 0){
            return solution;
        }
        sort(nums.begin(),nums.end());
        vector<pair<int,int> >dp(nums.size());
        int n = nums.size();
        for(int i=0;i<n;i++){
            dp[i].first = 1;
            dp[i].second = -1;
        }
        int maxIdx = 0,maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i].first<(dp[j].first+1)){
                        dp[i].first = dp[j].first+1;
                        dp[i].second = j;
                    }
                }
            }
            if(dp[i].first>maxi){
                maxIdx = i;
                maxi = dp[i].first;
            }
        }
        int i = maxIdx;
        while(dp[i].second!=(-1)){
            solution.push_back(nums[i]);
            i = dp[i].second;
        }
        solution.push_back(nums[i]);
        reverse(solution.begin(),solution.end());
        return solution;
    }
};