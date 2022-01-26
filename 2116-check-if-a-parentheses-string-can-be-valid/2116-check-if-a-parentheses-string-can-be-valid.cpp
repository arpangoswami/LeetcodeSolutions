class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() & 1){
            return false;
        }
        int left = 0,right = 0,n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || locked[i] == '0'){
                left++;
            }else{
                left--;
            }
            if(s[n-i-1] == ')' || locked[n-i-1] == '0'){
                right++;
            }else{
                right--;
            }
            if(left < 0 || right < 0){
                return false;
            }
        }
        return true;
    }
};