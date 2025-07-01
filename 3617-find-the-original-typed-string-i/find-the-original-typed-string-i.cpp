class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        int N = word.size();
        for(int i=0;i<N;){
            char ch = word[i];
            int cnt = 0;
            while(i < N && word[i] == ch){
                i++;
                cnt++;
            }
            ans += (cnt - 1);
        }
        return ans;
    }
};