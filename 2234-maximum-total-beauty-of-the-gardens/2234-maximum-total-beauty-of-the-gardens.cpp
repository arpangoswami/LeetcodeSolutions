typedef long long ll;
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        ll ans = 0LL;
        sort(flowers.begin(),flowers.end());
        int n = flowers.size();
        vector<ll> prefix(n);
        prefix[0] = flowers[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+flowers[i];
        }
        for(int i=n;i>=0;i--){
            if(i < n){
                ll toAdd = max(0,target - flowers[i]);
                if(newFlowers < toAdd){
                    break;
                }
                newFlowers -= toAdd;
                flowers.pop_back();
            }
            ll beautyFull = (n-i)*(ll)full;
            ll low = flowers[0],high = target-1;
            ll beautyPartial = 0LL;
            while(low <= high){
                ll mid = (low+high)/2;
                auto it = upper_bound(flowers.begin(),flowers.end(),mid);
                if(it == flowers.begin()){
                    low = mid+1;
                }else{
                    int incomplete = distance(flowers.begin(),it);
                    ll sum = prefix[incomplete-1];
                    ll needed = (mid*incomplete) - sum;
                    if(needed <= newFlowers){
                        low = mid+1;
                        beautyPartial = mid*partial;
                    }else{
                        high = mid-1;
                    }
                }
            }
            ans = max(ans,beautyFull+beautyPartial);
        }
        return ans;
    }
};