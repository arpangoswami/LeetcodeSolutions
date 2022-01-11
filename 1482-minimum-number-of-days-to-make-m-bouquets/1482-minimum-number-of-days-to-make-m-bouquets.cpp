class Solution {
    bool check(int day,vector<int> &arr,int num,int cons){
        int picked = 0;
        int now = 0;
        for(int x:arr){
            if(x <= day){
                now++;
                if(now == cons){
                    picked++;
                    now = 0;
                }
            }else{
                now = 0;
            }
        }
        return picked >= num;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
       int n = bloomDay.size();
        if((long long)m * (long long)k > (long long)n){
            return -1;
        }
        int low = 1,high = *max_element(bloomDay.begin(),bloomDay.end()),ans = high;
        //cout << check(5,bloomDay,3,1) << "\n";
        while(low <= high){
            int mid = (low+high)/2;
            if(check(mid,bloomDay,m,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};