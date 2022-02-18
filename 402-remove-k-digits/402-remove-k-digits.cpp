class Solution {
public:
    string removeKdigits(string s, int k) {
        if(s.size() == k){
            return "0";
        }
        for(int i=0;i<k;i++){
            int N = s.size();
            if(N == 0){
                break;
            }
            for(int j=0;j<(N-1);j++){
                if(s[j] > s[j+1]){
                    s.erase(s.begin()+j);
                    break;
                }
            }
            if(s.size() == N){
                s.pop_back();
            }
        }
        reverse(s.begin(),s.end());
        while(s.back() == '0'){
            s.pop_back();
        }
        reverse(s.begin(),s.end());
        return s == "" ? "0" : s;
    }
};