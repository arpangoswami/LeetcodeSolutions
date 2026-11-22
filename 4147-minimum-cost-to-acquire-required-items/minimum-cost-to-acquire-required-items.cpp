class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        if(cb <= c1 && cb <= c2){
            return cb * max(n1, n2);
        }else if(cb <= c1 && cb > c2){
            return cb * n1 + c2 * max(0LL, n2 - n1);
        }else if(cb <= c2 && cb > c1){
            return cb * n2 + c1 * max(0LL, n1 - n2);
        }else if(cb <= c1 + c2){
            return cb * min(n1, n2) + c1 * max(0LL, n1 - n2) + c2 * max(0LL, n2 - n1);
        }else{
            return c1 * n1 + c2 * n2;
        }
    }
};