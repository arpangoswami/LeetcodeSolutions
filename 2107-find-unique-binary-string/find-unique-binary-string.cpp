class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int N = nums.size(),n = nums.back().size();
        string ans;
        for(int i=0;i<n;i++){
            ans.push_back('0' + (nums[i][i] - '0') ^ 1);
        }
        return ans;
    }
};