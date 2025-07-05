class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501);
        for(int &x:arr){
            freq[x]++;
        }
        for(int i=500;i>=1;i--){
            if(i == freq[i]){
                return i;
            }
        }
        return -1;
    }
};