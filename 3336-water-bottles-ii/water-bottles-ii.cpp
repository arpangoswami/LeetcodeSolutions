class Solution {
    bool checkAllowed(int possible, int min, int sum){
        int extra = max((possible - min), 0);
        int total = (possible*(possible+1))/2 - (min * (min-1))/2;
        if(total <= (sum + extra)){
            return true;
        }
        return false;
    }
    int findExchanges(int total, int min){
        int high = total, low = min, ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(checkAllowed(mid, min, total)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return max((ans - min + 1), 0);
    }
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles,emptyBottles = numBottles;
        ans += findExchanges(emptyBottles, numExchange);
        return ans;
    }
};