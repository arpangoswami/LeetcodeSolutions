class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n = s.size();
        if(n == 0){
            return "";
        }
        int cols = n/rows;
        string ans = "";
        int gap = cols+1,idx = 0,start = 0;
        while(start < cols){
            ans.push_back(s[idx]);
            idx += gap;
            if(idx >= s.size()){
                idx = start+1;
                start++;
            }
        }
        while(ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};