class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        int N = word.size();
        for(int i=0;i<(N-1);i++){
            if(word[i] == word[i+1]){
                ans++;
            }
        }
        return ans;
    }
};