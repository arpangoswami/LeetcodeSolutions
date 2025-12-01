typedef long long ll;
class Solution {
    bool check(ll minRunTime,int n,vector<int> &batteries){
        int fulFill = 0;
        ll remaining = 0LL;
        for(int x:batteries){
            if(x >= minRunTime){
                fulFill++;
            }else{
                remaining += x;
                if(remaining >= minRunTime){
                    fulFill++;
                    remaining -= minRunTime;
                }
            }
        }
        return fulFill >= n;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll sum = accumulate(batteries.begin(),batteries.end(),0LL);
        sort(batteries.begin(),batteries.end(),greater<int>());
        ll low = 0LL,high = sum,ans = low;
        while(low <= high){
            ll mid = (low + high)/2;
            if(check(mid,n,batteries)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};