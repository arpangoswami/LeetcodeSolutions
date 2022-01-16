class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0,lastSpace = 0;
        int cnt = 0;
        for(int x:seats){
            if(x == 0){
                lastSpace++;
                if(cnt >= 1){
                    ans = max(ans,lastSpace/2);   
                }else{
                    ans = max(ans,lastSpace);
                }
                
            }else{
                lastSpace++;
                cnt++;
                ans = max(ans,lastSpace/2);
                lastSpace = 0;
            }
        }
        ans = max(ans,lastSpace);
        return ans;
    }
};