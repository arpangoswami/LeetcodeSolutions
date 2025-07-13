class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int N1 = players.size(), N2 = trainers.size();
        int ans = 0;
        for(int i=N1-1,j=N2-1;i>=0 && j>=0;i--){
            if(players[i] <= trainers[j]){
                ans++;
                j--;
            }
        }
        return ans;
    }
};