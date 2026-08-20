class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> first,second;
        first.push_back(nums[0]);
        second.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(first.back() > second.back()){
                first.push_back(nums[i]);
            }else{
                second.push_back(nums[i]);
            }
        }
        for(int x:second){
            first.push_back(x);
        }
        return first;
    }
};