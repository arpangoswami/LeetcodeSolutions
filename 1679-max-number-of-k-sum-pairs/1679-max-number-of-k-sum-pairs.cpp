class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        int ans1 = 0,ans2 = 0;
        for(auto it:mp){
            if(k & 1 == 0 && it.first == k/2){
                ans2 += (it.second)/2;
            }else if(mp.count(k-it.first)){
                ans1 += min(it.second,mp[k-it.first]);
            }
        }
        return ans1/2 + ans2;
    }
};