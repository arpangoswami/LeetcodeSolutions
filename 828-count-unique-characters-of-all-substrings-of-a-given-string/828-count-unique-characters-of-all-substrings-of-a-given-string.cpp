class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> positions(26);
        int n = s.size();
        int ans = 0;
        for(int i=0;i<26;i++){
            positions[i].push_back(-1);
        }
        for(int i=0;i<n;i++){
            positions[s[i]-'A'].push_back(i);
        }
        for(int i=0;i<26;i++){
            positions[i].push_back(n);
        }
        for(int i=0;i<26;i++){
            int N = positions[i].size();
            for(int j=1;j<(N-1);j++){
                int add = (positions[i][j+1] - positions[i][j])*(positions[i][j] - positions[i][j-1]);
                ans += add;
            }
        }
        return ans;
    }
};