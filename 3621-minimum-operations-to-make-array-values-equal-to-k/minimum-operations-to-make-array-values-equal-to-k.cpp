#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return true;
}();

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