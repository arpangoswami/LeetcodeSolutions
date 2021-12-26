class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(string &x:sentences){
            istringstream iss(x);
            int words = 0;
            string word;
            while(iss >> word){
                words++;
            }
            ans = max(ans,words);
        }
        return ans;
    }
};