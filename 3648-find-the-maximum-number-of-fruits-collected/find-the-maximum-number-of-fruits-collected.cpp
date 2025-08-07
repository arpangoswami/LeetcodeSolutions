class Solution {
    bool checkValiditySecond(int n,int x,int y){
        return (x >= 0 && x < n && y >= 0 && y < n && x > y);
    }
    bool checkValidityThird(int n,int x,int y){
        //cout << "n: " << n << " x: " << x << " y: " << y << '\n';
        return (x >= 0 && x < n && y >= 0 && y < n && y > x);
    }
    int getMaxFruitsSecondGuy(vector<vector<int>> fruits){
        int n = fruits.size();
        for(int j=n-3;j>=0;j--){
            for(int i=n-1;i>=max(j-1,n-j-1);i--){
                int firstMove = checkValiditySecond(n,i-1,j+1) ? fruits[i-1][j+1] : 0;
                int secondMove = checkValiditySecond(n,i,j+1) ? fruits[i][j+1] : 0;
                int thirdMove = checkValiditySecond(n, i+1, j+1) ? fruits[i+1][j+1] : 0;
                fruits[i][j] += max({firstMove, secondMove, thirdMove});
            }
        }
        return fruits[n-1][0];
    }
    int getMaxFruitsThirdGuy(vector<vector<int>> fruits){
        int n = fruits.size();
        for(int i=n-3;i>=0;i--){
            for(int j=n-1;j>=max(i-1,n-i-1);j--){
                int firstMove = checkValidityThird(n,i+1,j-1) ? fruits[i+1][j-1] : 0;
                int secondMove = checkValidityThird(n,i+1,j) ? fruits[i+1][j] : 0;
                int thirdMove = checkValidityThird(n, i+1, j+1) ? fruits[i+1][j+1] : 0;
                fruits[i][j] += max({firstMove, secondMove, thirdMove});
            }
        }
        return fruits[0][n-1];
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int firstGuy = 0, n = fruits.size();
        for(int i=0;i<n;i++){
            firstGuy += fruits[i][i];
        }
        int secondGuy = getMaxFruitsSecondGuy(fruits), thirdGuy = getMaxFruitsThirdGuy(fruits);
        return firstGuy + secondGuy + thirdGuy;
    }
};