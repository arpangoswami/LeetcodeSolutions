class Solution {
public:
    bool shouldSwap(vector<int>&nums,int start,int curr){
        for(int i=start;i<curr;i++){
            if(nums[i]==nums[curr]) return false;
        }
        return true;
    }
    void allDistinctPermute(vector<vector<int> >&ans,vector<int>&nums,int i,int n){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            if(shouldSwap(nums,i,j)){
                swap(nums[i],nums[j]);
                allDistinctPermute(ans,nums,i+1,n);
                swap(nums[i],nums[j]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> >ans;
        allDistinctPermute(ans,nums,0,nums.size());
        return ans;
    }
};
