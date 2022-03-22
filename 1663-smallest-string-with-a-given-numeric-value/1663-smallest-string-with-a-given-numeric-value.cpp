class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i=0;i<n;i++){
            ans.push_back('a');
        }
        k-=n;
        for(int i=n-1;i>=0 && k>0;i--){
            if(k >= 25){
                ans[i] = 'z';
                k-=25;
            }else{
                ans[i] = 'a'+k;
                k = 0;
            }
        }
        return ans;
    }
};