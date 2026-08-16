class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> rem(3);
        for(int x:stones){
            rem[x%3]++;
        }
        if(min(rem[1],rem[2]) == 0){
            return (max(rem[1],rem[2]) > 2 && (rem[0] % 2 > 0));
        }
        return (abs(rem[1] - rem[2]) > 2 || (rem[0] % 2 == 0));
    }
};