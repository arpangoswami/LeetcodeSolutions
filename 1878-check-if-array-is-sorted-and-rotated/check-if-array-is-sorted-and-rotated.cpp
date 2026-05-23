class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(),seq = 0;
        for(int i=0;i<(n-1);i++){
        	if(nums[i] > nums[i+1]){
        		seq++;
        	}
        	if(seq > 1){
        		return false;
        	}
        }
        if(seq == 0){
        	return true;
        }
        return nums.back() <= nums[0];
    }
};