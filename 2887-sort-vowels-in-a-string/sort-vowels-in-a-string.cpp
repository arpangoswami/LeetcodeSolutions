class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowel = {'a','e','i','o','u','A','E','I','O','U'};
        vector<char> vowels;
        int n = s.size();
        vector<char> ans(n,'$');
        for(int i=0;i<n;i++){
            if(!vowel.count(s[i])){
                ans[i] = s[i];
            }else{
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end(),greater<char>());
        for(int i=0;i<n;i++){
            if(ans[i] == '$'){
                ans[i] = vowels.back();
                vowels.pop_back();
            }
        }
        string sol;
        for(char ch:ans){
            sol.push_back(ch);
        }
        return sol;
    }
};