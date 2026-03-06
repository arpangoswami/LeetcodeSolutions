class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zeroFound = false;
        for(char &ch:s){
            if(ch == '0'){
                zeroFound = true;
            }
            if(zeroFound && ch == '1'){
                return false;
            }
        }
        return true;
    }
};