class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mapping;
        unordered_map<string,char> reverseMapping;
        istringstream iss(s);
        string word;
        int n = pattern.size(),i = 0;
        while(iss >> word){
            if(i >= n){
                return false;
            }
            if(mapping.count(pattern[i]) && mapping[pattern[i]] != word){
                return false;
            }else if(reverseMapping.count(word) && 
                     reverseMapping[word] != pattern[i]){
                return false;
            }else if(!mapping.count(pattern[i]) && !reverseMapping.count(word)){
                mapping[pattern[i]] = word;
                reverseMapping[word] = pattern[i];
            }
            i++;
        }
        return i == n;
    }
};