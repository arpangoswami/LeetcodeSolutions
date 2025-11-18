class Solution {
public:
    bool isOneBitCharacter(vector<int>& s) {
        bool secondLast = true,last = (s[0] == 0);
        int n = s.size();
        for(int i=1;i<n;i++){
            bool curr = false;
            if(s[i] == 0){
                curr = last; // 0
                if(!curr){
                    if(s[i-1] == 1){
                        curr = secondLast; //10
                    }
                }
            }else if(s[i] == 1){
                if(s[i-1] == 1){
                    curr = secondLast; //11
                }
            }
            secondLast = last;
            last = curr;
        }
        return n == 0 ? true : secondLast;
    }
};