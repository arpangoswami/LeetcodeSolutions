using ll = long long;
class Solution {
    ll getMaxIterations(int val, ll maxTimeAllowed, const int &mountainHeight){
        ll high = mountainHeight;
        ll low = 0, ans = low;
        while(low <= high){
            ll mid = (low + high)/2;
            ll sum = (mid*(mid+1))/2;
            ll total = val * sum;
            if(total <= maxTimeAllowed){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        } 
        return ans;
    }
    bool check(ll maxTimeAllowed, int mountainHeight, vector<int> &workerTimes){
        int heightTillNow = 0;
        for(int i=0;i<workerTimes.size();i++){
            ll maxIterations = getMaxIterations(workerTimes[i], maxTimeAllowed, mountainHeight);
            heightTillNow += maxIterations;
            if(heightTillNow >= mountainHeight){
                return true;
            }
        }
        return false;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int minWorker = *min_element(workerTimes.begin(), workerTimes.end());
        ll maxSum = ((ll)mountainHeight * (ll)(mountainHeight+1))/2;
        ll maxTime = (ll)minWorker * (ll)maxSum;
        ll low = 1,high = maxTime, ans = maxTime;
        while(low <= high){
            ll mid = (low + high)/2;
            if(check(mid, mountainHeight, workerTimes)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};