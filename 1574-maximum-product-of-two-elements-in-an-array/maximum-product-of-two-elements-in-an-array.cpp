class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxm = -1,smax = -1;
        for(int x:nums){
            if(x >= maxm){
                smax = maxm;
                maxm = x;
            }else if(x >= smax){
                smax = x;
            }
        }
        return (maxm - 1)*(smax - 1);
    }
};