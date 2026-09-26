class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> valuePair;
        for(vector<string> &v:knowledge){
            valuePair[v[0]] = v[1];
        }
        string ans;
        int N = s.size();
        for(int i=0;i<N;){
            if(s[i] == '('){
                string nested;
                i++;
                while(s[i] != ')'){
                    nested.push_back(s[i]);
                    i++;
                }
                i++;
                if(valuePair.count(nested)){
                    ans += valuePair[nested];
                }else{
                    ans.push_back('?');
                }
            }else{
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};