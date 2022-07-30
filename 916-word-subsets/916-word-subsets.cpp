class Solution {
    bool isUniversal(string &x,vector<int> &freqMap){
        vector<int> individual(26);
        for(char &c:x){
            individual[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freqMap[i] > individual[i]){
                return false;
            }
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freqMap(26);
        for(string &x:words2){
            vector<int> individual(26);
            for(char &c:x){
                individual[c-'a']++;
            }
            for(int i=0;i<26;i++){
                freqMap[i] = max(freqMap[i],individual[i]);
            }
        }
        vector<string> ans;
        for(string &x:words1){
            if(isUniversal(x,freqMap)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};