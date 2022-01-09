class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int,int> original = {0,0};
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        const int dirSize = 4;
        int ptr = 0;
        for(char c:instructions){
            if(c == 'L'){
                ptr--;
                ptr += dirSize;
                ptr %= dirSize;
            }else if(c == 'R'){
                ptr++;
                ptr %= dirSize;
            }else{
                original = {original.first + directions[ptr].first,
                           original.second + directions[ptr].second};
            }
        }
        if(original.first == 0 && original.second == 0){
            return true;
        }
        return ptr != 0;
    }
};