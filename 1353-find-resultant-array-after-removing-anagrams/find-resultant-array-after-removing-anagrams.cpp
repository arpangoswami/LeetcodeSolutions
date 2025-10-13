class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        vector<int> prevFreq(26);
        int n = words.size();
        for(int i=0;i<n;i++){
            vector<int> currFreq(26);
            for(char &ch:words[i]){
                currFreq[ch - 'a']++;
            }
            bool flag = true;
            for(int i=0;i<26;i++){
                if(currFreq[i] != prevFreq[i]){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                ans.push_back(words[i]);
                prevFreq = currFreq;
            }
        }
        return ans;
    }
};