class Solution {
public:
    bool detectCapitalUse(string word) {
        int caps = 0,n = word.size();
        for(int i=0;i < n;i++){
            if(word[i]>=65 && word[i]<=90){
                caps++;
            }
        }
        return (caps == n || caps == 0) ? true : (caps > 1) ? false : (word[0]>=65 && word[0]<=90) ? true : false;
    }
};