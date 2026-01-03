class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[5001][4][4][4];
    int recSolve(int i,int m1,int m2,int m3,int n){
        if(i == n){
            return 1;
        }
        if(dp[i][m1][m2][m3] != -1){
            return dp[i][m1][m2][m3];
        }
        int ans = 0;
        for(int a=0;a<=2;a++){
            for(int b=0;b<=2;b++){
                for(int c = 0;c<=2;c++){
                    if(a == b || b == c || a == m1 || b == m2 || c == m3){
                        continue;
                    }
                    ans += recSolve(i+1,a,b,c,n);
                    ans %= mod;
                }
            }
        }
        return dp[i][m1][m2][m3] = ans;
    }
    int numOfWays(int n) {
        for(int i=0;i<=n;i++){
            for(int j=0;j<=3;j++){
                for(int k=0;k<=3;k++){
                    for(int l=0;l<=3;l++){
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        int ans = 0;
        for(int a=0;a<=2;a++){
            for(int b=0;b<=2;b++){
                for(int c = 0;c<=2;c++){
                    if(a == b || b == c){
                        continue;
                    }
                    ans += recSolve(1,a,b,c,n);
                    ans %= mod;
                }
            }
        }
        return ans;
    }
};