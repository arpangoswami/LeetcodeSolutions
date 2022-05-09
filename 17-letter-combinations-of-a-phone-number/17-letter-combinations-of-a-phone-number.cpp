class Solution {
    vector<string> codes = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void allCombinations(const string &digits,int idx,vector<string> &ans,string &message){
        if(idx == digits.size()){
            ans.push_back(message);
            return;
        }
        string &code = codes[digits[idx] - '0'];
        for(char c:code){
            message.push_back(c);
            allCombinations(digits,idx+1,ans,message);
            message.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        vector<string> ans;
        string currentMessage;
        allCombinations(digits,0,ans,currentMessage);
        return ans;
    }
};