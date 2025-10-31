class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<bool> appeared(nums.size());
        vector<int> ans;
        for(int x:nums){
            if(appeared[x]){
                ans.push_back(x);
            }else{
                appeared[x] = true;
            }
        }
        return ans;
    }
};