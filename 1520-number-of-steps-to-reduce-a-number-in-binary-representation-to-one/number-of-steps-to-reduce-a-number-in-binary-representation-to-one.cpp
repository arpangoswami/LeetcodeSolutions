class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        while(s.size() > 1){
            if(s.back() == '1'){
                int N = s.size(), i = N-2;
                for(i=N-1;i>=0;i--){
                    if(s[i] == '1'){
                        s[i] = '0';
                    }else{
                        s[i] = '1';
                        break;
                    }
                }
                if(i < 0){
                    s = "1" + s;
                }
            }else{
                s.pop_back();
            }
            ans++;
        }
        return ans;
    }
};