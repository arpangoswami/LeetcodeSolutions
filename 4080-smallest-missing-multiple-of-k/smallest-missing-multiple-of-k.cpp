class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        for(int i=1;i<=(nums.size() + 1);i++){
            if(!st.count(i*k)){
                return i*k;
            }
        }
        return -1;
    }
};