class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n = tokens.size();
        if(n == 0){
            return 0;
        }
        int i = 0,j = n-1;
        sort(tokens.begin(),tokens.end());
        int maxScore = 0,currScore = 0;
        while(i<=j && (P >= tokens[i] || currScore > 0)){
            while(i<=j && P>=tokens[i]){
                P-=tokens[i];
                i++;
                currScore++;
                
            }
            maxScore = max(maxScore,currScore);
            if(i<=j && currScore > 0){
                P+=tokens[j];
                j--;
                currScore--;
            }
        }
        return maxScore;
    }
};