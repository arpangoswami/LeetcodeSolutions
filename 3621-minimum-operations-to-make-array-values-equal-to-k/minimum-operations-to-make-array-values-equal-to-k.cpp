class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        int firstVal = *st.begin(), n = st.size();
        if(k > firstVal){
            return -1;
        } else if(k == firstVal){
            return n - 1;
        }
        return n;
    }
};