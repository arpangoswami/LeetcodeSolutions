class Solution {
    void allPossibleStrings(vector<string> &ans,string &original,int idx,string &possible){
        if(idx >= original.size()){
            ans.push_back(possible);
            return;
        }
        char c = original[idx];
        idx++;
        if(c == '{'){
            vector<char> arr;
            while(original[idx] != '}'){
                if(original[idx] == ','){
                    idx++;
                    continue;
                }
                arr.push_back(original[idx++]);
            }
            idx++;
            for(char c:arr){
                possible.push_back(c);
                allPossibleStrings(ans,original,idx,possible);
                possible.pop_back();
            }
        }else{
            possible.push_back(c);
            allPossibleStrings(ans,original,idx,possible);
            possible.pop_back();
        }
    }
public:
    vector<string> expand(string s) {
        vector<string> ans;
        string possible;
        allPossibleStrings(ans,s,0,possible);
        sort(ans.begin(),ans.end());
        return ans;
    }
};