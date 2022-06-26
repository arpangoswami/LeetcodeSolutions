class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int possibleAns = 0;
        for(int i=0;i<k;i++){
            possibleAns += cardPoints[i];
        }
        int ptr = k-1,ans = possibleAns;
        for(int i=n-1;i>=(n-k);i--){
            possibleAns -= cardPoints[ptr];
            ptr--;
            possibleAns += cardPoints[i];
            ans = max(ans,possibleAns);
        }
        return ans;
    }
};