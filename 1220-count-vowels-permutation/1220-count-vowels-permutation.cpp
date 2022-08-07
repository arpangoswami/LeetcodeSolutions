class Solution {
    constexpr static int MOD = 1e9+7;
    int recDp(int num,int position,int length,vector<vector<int>> &dp){
        if(position == length - 1){
            return 1LL;
        }
        if(dp[num][position] != -1){
            return dp[num][position];
        }
        int &ans = dp[num][position] = 0;
        switch (num){
            case 0:
                ans += recDp(1,position+1,length,dp);
                break;
            case 1:
                ans += recDp(0,position+1,length,dp);
                ans %= MOD;
                ans += recDp(2,position+1,length,dp);
                ans %= MOD;
                break;
            case 2:
                for(int i=0;i<5;i++){
                    if(i == 2){
                        continue;
                    }
                    ans += recDp(i,position+1,length,dp);
                    ans %= MOD;
                }
                break;
            case 3:
                ans += recDp(2,position+1,length,dp);
                ans %= MOD;
                ans += recDp(4,position+1,length,dp);
                ans %= MOD;
                break;
            case 4:
                ans += recDp(0,position+1,length,dp);
                break;
            default:
                ans = 0;
        }
        return ans;
    }
    
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(5,vector<int>(n+1,-1));
        int ans = 0;
        for(int i=0;i<5;i++){
            ans += recDp(i,0,n,dp);
            ans %= MOD;
        }
        return ans;
    }
};