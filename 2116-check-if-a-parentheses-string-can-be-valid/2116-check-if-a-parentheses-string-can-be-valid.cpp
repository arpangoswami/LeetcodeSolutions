class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() & 1){
            return false;
        }
        int remaining = 0,n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || locked[i] == '0'){
                remaining++;
            }else{
                remaining--;
            }
            if(remaining < 0){
                return false;
            }
        }
        if(remaining < 0){
            return false;
        }
        remaining = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == ')' || locked[i] == '0'){
                remaining++;
            }else{
                remaining--;
            }
            if(remaining < 0){
                return false;
            }
        }
        return remaining >= 0;
    }
};