class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minm = INT_MAX,maxm = INT_MIN;
        for(int &x:nums){
            if(minm > x){
                minm = x;
            }
            if(maxm < x){
                maxm = x;
            }
        }
        return __gcd(minm, maxm);
    }
};