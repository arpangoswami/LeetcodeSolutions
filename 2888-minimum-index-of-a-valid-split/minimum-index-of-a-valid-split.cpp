class Solution {
    int findMajorityElement(vector<int> &nums){
        int n = nums.size(), candidate = -1, votes = 0;
        for(int x:nums){
            if(votes == 0){
                candidate = x;
                votes = 1;
            } else {
                if(candidate == x){
                    votes++;
                }else{
                    votes--;
                }
            }
        }
        return candidate;
    }
public:
    int minimumIndex(vector<int>& nums) {
        int num = findMajorityElement(nums), n = nums.size();
        int tillNow = 0, freq = count(nums.begin(), nums.end(), num);
        for(int i=0;i<n;i++){
            if(nums[i] == num){
                tillNow++;
                freq--;
            }
            int firstHalfReq = (i+1)/2 + 1, secondHalfReq = (n-i-1)/2 + 1;
            if(tillNow >= firstHalfReq && freq >= secondHalfReq){
                return i;
            }
        }
        return -1;
    }
};