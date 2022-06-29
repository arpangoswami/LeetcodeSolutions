class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),ans = 0,duplicates = 0;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                duplicates++;
                ans -= nums[i];
            }else{
                int numsPlaced = min(nums[i]-nums[i-1]-1,duplicates);
                int add = numsPlaced * nums[i-1] + (numsPlaced*(numsPlaced+1))/2;
                ans += add;
                duplicates -= numsPlaced;
            }
            //cout<<"ans: "<<ans<<"\n";
        }
        if(duplicates > 0){
            int add = (duplicates*(duplicates+1))/2 + duplicates*nums.back();
            ans += add;
            duplicates = 0;
            //cout<<"ans here: "<<ans<<"\n";
        }
        return ans;
    }
};