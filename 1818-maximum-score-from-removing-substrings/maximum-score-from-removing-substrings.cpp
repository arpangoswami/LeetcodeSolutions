class Solution {
    int maxScore(string &s, char first, char second, int score){
        string copy;
        int ans = 0;
        for(char &ch:s){
            if(copy.size() > 0 && ch == second && copy.back() == first){
                copy.pop_back();
                ans += score;
            }else{
                copy.push_back(ch);
            }
        }
        s = copy;
        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
        if(y > x){
            return maxScore(s, 'b', 'a', y) + maxScore(s, 'a', 'b', x);
        }
        return maxScore(s, 'a', 'b', x) + maxScore(s, 'b', 'a', y);
    }
};