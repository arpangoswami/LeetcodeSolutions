class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
        vector<string> ans;
        int n = nums.size();
        for(int i=0;i<n;){
            string range = to_string(nums[i]);
            int j = i+1;
            while(j < n && nums[j] == 1+nums[j-1]){
                j++;
            }
            if(j > (i+1)){
                range += "->";
                range += to_string(nums[j-1]);
            }
            ans.push_back(range);
            i = j;
        }
        return ans;
    }
};