
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
    void dfs(string &s, int a, int b, unordered_set<string> &visited,string &ans){
        visited.insert(s);
        ans = min(ans, s);
        string copy = s;
        for(int i=1;i<copy.size();i+=2){
            char ch;
            ch = '0' + (s[i] - '0' + a)%10;
            copy[i] = ch;
        }
        if(!visited.count(copy)){
            dfs(copy, a, b, visited, ans);
        }
        string copy2;
        for(int i=b;i<s.size();i++){
            copy2.push_back(s[i]);
        }
        for(int i=0;i<b;i++){
            copy2.push_back(s[i]);
        }
        if(!visited.count(copy2)){
            dfs(copy2, a, b, visited, ans);
        }
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string ans = s;
        dfs(s, a, b, visited, ans);
        return ans;
    }
};