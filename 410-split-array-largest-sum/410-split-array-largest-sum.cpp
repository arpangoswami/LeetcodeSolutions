class Solution {
    bool check(int maxSum,vector<int> &nums,int maxPicked){
        int picked = 1,sumTillNow = 0;
        for(int x:nums){
            sumTillNow += x;
            if(sumTillNow > maxSum){
                sumTillNow = x;
                picked++;
            }
        }
        return picked <= maxPicked;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int low = *max_element(nums.begin(),nums.end()),high = totalSum,ans = totalSum;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(mid,nums,m)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};