class Solution {
public:
    string removeKdigits(string s, int k) {
        if(s.size() == k){
            return "0";
        }
        for(int i=0;i<k;++i){
            int l = s.size();
            for(int j=0;j<s.size()-1;j++){
                if(s[j]>s[j+1]){
                    s.erase(s.begin()+j);
                    break;
                }
            }
            if(s.size() == l){
                s.erase(l-1,1);
            }
        }
        int zero_cnt = 0,m = s.size();
        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                zero_cnt++;
            }
            else{
                break;
            }
        }
        s = s.substr(zero_cnt);
        if(zero_cnt == m){
            s = "0";
        }
        return s;
    }
};