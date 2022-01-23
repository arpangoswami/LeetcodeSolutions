class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int len1 = floor(log10(low)+1),len2 = floor(log10(high)+1);
        vector<int> ans;
        for(int len=len1;len<=len2;len++){
            for(int i=1;i<=(9-len+1);i++){
                int num = i;
                for(int j=1;j<len;j++){
                    int last = num%10;
                    int now = last+1;
                    num = num*10+now;
                }
                ans.push_back(num);
            }
        }
        reverse(ans.begin(),ans.end());
        while(!ans.empty() && ans.back() < low){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        while(!ans.empty() && ans.back() > high){
            ans.pop_back();
        }
        return ans;
    }
};