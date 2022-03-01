class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> solution;
        solution.push_back(0);
        if(num == 0){
            return solution;
        }
        solution.push_back(1);
        if(num == 1){
            return solution;
        }
        int prev = 0,next = 2;
        for(int i=2;i<=num;++i){
            if(i == next){
                prev = 0;
                next *= 2;
            }
            solution.push_back(solution[prev++] + 1);
        }
        return solution;
    }
};