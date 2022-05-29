class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(),allPresent = (1 << 26) - 1;
        vector<int> charIn(n);
        for(int i=0;i<n;i++){
            int mask = 0;
            for(char c:words[i]){
                mask |= (1 << (c - 'a'));
                if(mask == allPresent){
                    break;
                }
            }
            charIn[i] = mask;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(charIn[i] == allPresent){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(charIn[j] == allPresent){
                    continue;
                }
                if((charIn[i] & charIn[j]) == 0 && 
                   (words[i].size()*words[j].size()) > ans){
                    ans = words[i].size()*words[j].size();
                }
            }
        }
        return ans;
    }
};