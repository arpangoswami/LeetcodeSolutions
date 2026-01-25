class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] & 1){
                // if all 1s
                int add1 = nums[i] + 1;
                if((add1 & nums[i]) == 0){
                    nums[i] >>= 1;
                }else{
                    for(int j=1;j<=10;j++){
                        if((nums[i] & (1 << j)) == 0){
                            nums[i] ^= (1 << (j-1));
                            break;
                        }
                    }
                }
            }else{
                nums[i] = -1;
            }
        }
        return nums;
    }
};