class Solution {
    int getDist(char ch1, char ch2){
        int rowFirst = (ch1 - 'A')/6, colFirst = (ch1 - 'A')%6;
        int rowSecond = (ch2 - 'A')/6, colSecond = (ch2 - 'A')%6;
        return abs(rowSecond - rowFirst) + abs(colSecond - colFirst);
    }
    int recDp(string &word, const int &length, int i, int j, int k, vector<vector<vector<int>>> &dp){
        if(k >= length){
            return dp[i][j][k] = 0;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        if(i == 0){
            return dp[i][j][k] = recDp(word, length, word[0] - 'A' + 1, j, k+1, dp);
        }else if(j == 0){
            int secondFingerStart = recDp(word, length, i, word[k]+1-'A', k+1, dp);
            char chFirstFinger = 'A' + i - 1;
            int firstFingerAns = getDist(word[k], chFirstFinger) + recDp(word, length, word[k]+1-'A', j, k+1, dp);
            return dp[i][j][k] = min(secondFingerStart, firstFingerAns);
        }
        char chFirstFinger = 'A' + i - 1;
        char chSecondFinger = 'A' + j - 1;
        int firstFingerMovement = getDist(word[k], chFirstFinger);
        int secondFingerMovement = getDist(word[k], chSecondFinger);
        return dp[i][j][k] = min(firstFingerMovement + recDp(word, length, word[k]+1 - 'A', j, k+1, dp), secondFingerMovement + recDp(word, length, i, word[k]+1-'A', k+1, dp));
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp(27, vector<vector<int>>(27, vector<int>(n+2, -1)));
        return recDp(word, n, 0, 0, 0, dp);
    }
};