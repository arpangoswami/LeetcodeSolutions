using ll = long long;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans = 0,currLength = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                currLength++;
            }else{
                ans += (currLength*(currLength+1))/2;
                currLength = 0;
            }
        }
        ans += (currLength*(currLength+1))/2;
        return ans;
    }
};