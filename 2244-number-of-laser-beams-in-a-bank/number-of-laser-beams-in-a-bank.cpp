class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCount = 0, ans = 0;
        for(string &x:bank){
            int cntOne = count(x.begin(), x.end(), '1');
            if(cntOne == 0){
                continue;
            }
            ans += (prevCount * cntOne);
            prevCount = cntOne;
        }
        return ans;
    }
};