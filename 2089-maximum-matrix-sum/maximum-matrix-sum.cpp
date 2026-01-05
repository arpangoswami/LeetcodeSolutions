class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0,min_element = 1e6;
        int negatives = 0;
        bool zeros = false;
        for(vector<int> &v:matrix){
            for(int &x:v){
                if(x < 0){
                    negatives++;
                }
                if(x == 0){
                    zeros = true;
                }
                ans += abs(x);
                min_element = min(abs(min_element),(long long)abs(x));
            }
        }
        if(negatives % 2 == 1){
            ans -= 2*abs(min_element);
        }
        return ans;
    }
};