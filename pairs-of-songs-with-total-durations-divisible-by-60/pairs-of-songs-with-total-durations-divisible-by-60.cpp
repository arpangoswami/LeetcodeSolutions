class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> freq(60);
        for(int x:time){
            freq[x%60]++;
        }
        int ans = 0;
        for(int i=0;i<=30;i++){
            if(i == 0){
                ans += (freq[0]*(freq[0]-1))/2;
            }else if(i == 30){
                ans += (freq[30]*(freq[30]-1))/2; 
            }else{
                ans += (freq[i]*freq[60-i]);
            }
        }
        return ans;
    }
};