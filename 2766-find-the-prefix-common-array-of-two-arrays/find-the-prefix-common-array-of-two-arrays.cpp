class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        long long num1 = 0, num2 = 0;
        int n = A.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            num1 |= (1LL << A[i]);
            num2 |= (1LL << B[i]);
            ans[i] = __builtin_popcountll(num1 & num2);
        }
        return ans;
    }
};