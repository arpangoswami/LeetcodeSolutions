class Solution {
    bool check(vector<int> &piles,int mid,int h){
        int hrs = 0;
        for(int x:piles){
            hrs += (x+mid-1)/mid;
            if(hrs > h){
                return false;
            }
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = *max_element(piles.begin(),piles.end()),ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(piles,mid,h)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};