typedef long long ll;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n);
        unordered_map<int,vector<ll>> indices;
        for(int i=0;i<n;i++){
            indices[nums[i]].push_back(i);
        }
        for(auto it:indices){
            vector<ll> v = it.second;
            ll totalSum = accumulate(v.begin(),v.end(),0LL);
            ll sumBefore = 0LL;
            ll N = v.size(),before = 0;
            for(ll index:v){
                totalSum -= index;
                ans[index] = (totalSum - (N-before-1)*index) + (before*index - sumBefore);
                before++;
                sumBefore += index;
            }
            
        }
        return ans;
    }
};