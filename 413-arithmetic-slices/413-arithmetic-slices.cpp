class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(A.size() <= 2){
            return 0;
        }
        int ans = 0, diff = A[1] - A[0],curr = 2;
        for(int i=2;i<n;i++){
            if(A[i] - A[i-1] == diff){
                curr++;
                ans += max(0,curr-2);
            }else{
                diff = A[i] - A[i-1];
                curr = 2;
            }
        }
        return ans;
    }
};