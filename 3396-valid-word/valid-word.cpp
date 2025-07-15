class Solution {
    inline static const unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
public:
    bool isValid(string word) {
        if(word.size() < 3){
            return false;
        }
        bool vowelFound = false,consonantFound = false;
        for(char &ch:word){
            if(!isdigit(ch) && !isalpha(ch)){
                return false;
            }
            if(isalpha(ch)){
                if(vowels.count(ch)){
                    vowelFound = true;
                }else{
                    consonantFound = true;
                }
            }
        }
        return vowelFound && consonantFound;
    }
};