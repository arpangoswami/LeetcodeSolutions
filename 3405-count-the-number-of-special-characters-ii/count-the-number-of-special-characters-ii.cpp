class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLow(26, -1), firstUpper(26, -1);
        int n = word.size();
        for(int i=n-1;i>=0;i--){
            if(islower(word[i]) && lastLow[word[i] - 'a'] == -1){
                lastLow[word[i] - 'a'] = i;
            }
        }
        for(int i=0;i<n;i++){
            if(isupper(word[i]) && firstUpper[word[i] - 'A'] == -1){
                firstUpper[word[i] - 'A'] = i;
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(lastLow[i] != -1 && firstUpper[i] != -1 && lastLow[i] < firstUpper[i]){
                ans++;
            }
        }
        return ans;
    }
};