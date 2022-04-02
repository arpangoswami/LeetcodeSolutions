class Solution {
    bool isValid(string &s,int low,int high,int remaining){
        while(low < high){
            if(s[low] != s[high]){
                if(remaining > 0){
                    return isValid(s,low+1,high,0) || isValid(s,low,high-1,0);
                }else{
                    return false;
                }
            }else{
                low++;
                high--;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        return isValid(s,0,n-1,1);
    }
};