class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<(n-2);i++){
            if(i == 0 || nums[i] != nums[i-1]){
                int required = -nums[i];
                int low = (i+1),high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] == required){
                        ans.push_back({nums[i],nums[low],nums[high]});
                        while(low < high && nums[low] == ans.back()[1]){
                            low++;
                        }
                        while(low < high && nums[high] == ans.back()[2]){
                            high--;
                        }
                    }else if(nums[low] + nums[high] > required){
                        high--;
                    }else{
                        low++;
                    }
                }
            }
        }
        return ans;
    }
};