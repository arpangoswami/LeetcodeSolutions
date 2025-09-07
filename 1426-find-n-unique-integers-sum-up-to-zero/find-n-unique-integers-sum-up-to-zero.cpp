class Solution {
public:
    vector<int> sumZero(int n) {
        int negative = n/2;
        vector<int> ans;
        for(int i=1;i<=negative;i++){
            ans.push_back(i);
            ans.push_back(-i);
        }
        if(n & 1){
            ans.push_back(0);
        }
        return ans;
    }
};