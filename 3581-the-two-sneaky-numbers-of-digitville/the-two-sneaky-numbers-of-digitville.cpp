class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> appeared;
        vector<int> ans;
        for(int x:nums){
            if(appeared.count(x)){
                ans.push_back(x);
            }else{
                appeared.insert(x);
            }
        }
        return ans;
    }
};