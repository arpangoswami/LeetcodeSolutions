class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = n+1;
        for(int i=1;i<=6;i++){
            int countA = 0,countB = 0;
            bool flag = true;
            for(int j=0;j<n;j++){
                if(tops[j] == i){
                    countA++;
                }
                if(bottoms[j] == i){
                    countB++;
                }
                if(tops[j] != i && bottoms[j] != i){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = min({ans,n-countA,n-countB});
            }
        }
        return ans > n ? -1 : ans;
    }
};