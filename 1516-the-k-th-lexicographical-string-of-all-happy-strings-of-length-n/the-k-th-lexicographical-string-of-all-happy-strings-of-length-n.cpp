class Solution {
    void recSolve(const int length,const int k, int& iteration, string &baseString, string &ans, vector<char> &letters){
        if(baseString.length() == length){
            iteration++;
            if(iteration == k){
                ans = baseString;
            }
            return;
        }
        if(iteration == k){
            return;
        }
        for(char &ch:letters){
            if(baseString.size() > 0 && ch == baseString.back()){
                continue;
            }
            baseString.push_back(ch);
            recSolve(length, k, iteration, baseString, ans, letters);
            baseString.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string ans, baseString;
        vector<char> letters = {'a', 'b', 'c'};
        int iteration = 0;
        recSolve(n, k, iteration, baseString, ans, letters);
        return ans;
    }
};