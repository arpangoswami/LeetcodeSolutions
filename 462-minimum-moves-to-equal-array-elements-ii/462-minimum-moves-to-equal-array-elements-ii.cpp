typedef long long ll;
class Solution {
public:
    ll calSum(int low,int high,vector<ll> &pref){
        if(low > high){
            return 0;
        }
        return pref[high] - ((low == 0) ? 0 : pref[low-1]);
    }
    ll minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<ll> pref(nums.size());
        pref[0] = nums[0];
        int n = nums.size();
        for(int i=1;i<nums.size();i++){
            pref[i] = pref[i-1] + nums[i];
        }
        ll ans = 1e15;
        for(int i=0;i<n;i++){
            ll toEqual = nums[i];
            ll op1 = (toEqual * (ll)i) - calSum(0,i-1,pref);
            ll op2 = calSum(i+1,n-1,pref) - (toEqual * (ll)(n-i-1));
            //cout<<"i: "<<i<<" op1: "<<op1<<" op2: "<<op2<<"\n";
            ans = min(ans,op1 + op2);
        }
        return ans;
    }
};