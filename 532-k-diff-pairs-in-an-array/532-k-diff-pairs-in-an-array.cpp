class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_set<int> st;
        set<pair<int,int>> taken;
        for(int x:nums){
            if(st.count(x-k) && !taken.count({x,x-k}) && !taken.count({x-k,x})){
                ans++;
                taken.insert({x,x-k});
                taken.insert({x-k,x});
            }
            if(st.count(x+k) && !taken.count({x,x+k}) && !taken.count({x+k,x})){
                ans++;
                taken.insert({x,x+k});
                taken.insert({x+k,x});
            }
            st.insert(x);
        }
        return ans;
    }
};