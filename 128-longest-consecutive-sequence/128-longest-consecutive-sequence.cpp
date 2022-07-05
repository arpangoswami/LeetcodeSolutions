class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(const int &x:nums){
            hashSet.insert(x);
        }
        int ans = 0;
        for(const int &x:nums){
            if(hashSet.count(x-1)){
                continue;
            }
            int val = x,curr = 0;
            while(hashSet.count(val)){
                curr++;
                val++;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};