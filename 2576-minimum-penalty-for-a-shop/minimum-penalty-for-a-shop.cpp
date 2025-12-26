class Solution {
public:
    int bestClosingTime(string customers) {
        int yCount = count(customers.begin(),customers.end(),'Y');
        int n = customers.size(), nCount = n - yCount,nTillNow = 0;
        int penaltyTillNow = yCount,ans = 0;
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y'){
                yCount--;
            }else{
                nTillNow++;
            }
            if(nTillNow + yCount < penaltyTillNow){
                ans = i+1;
                penaltyTillNow = nTillNow + yCount;
            }
        }
        return ans;
    }
};