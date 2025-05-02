class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> state(n,0);
        int pushPower = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'R'){
                pushPower = n;
            }else if(s[i] == 'L'){
                pushPower = 0;
            }
            if(pushPower > 0){
                state[i] = pushPower;
                pushPower--;
            }
        }
        pushPower = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == 'L'){
                pushPower = -n;
            }else if(s[i] == 'R'){
                pushPower = 0;
            }
            if(pushPower < 0){
                state[i] += pushPower;
                pushPower++;
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(state[i] > 0){
                ans.push_back('R');
            }else if(state[i] < 0){
                ans.push_back('L');
            }else{
                ans.push_back('.');
            }
        }
        return ans;
    }
};