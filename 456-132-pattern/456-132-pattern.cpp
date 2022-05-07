class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return 0;
        }
        multiset<int> mset;
        for(int i=1;i<n;i++){
            mset.insert(nums[i]);
        }
        int minimum = nums[0];
        for(int i=1;i<(n-1);i++){
            int val = nums[i];
            auto it1 = mset.find(val);
            mset.erase(it1);
            auto it = mset.upper_bound(minimum);
            if(it != mset.end() && *it > minimum && *it < val){
                return true;
            }
            minimum = min(minimum,val);
        }
        return false;
    }
};