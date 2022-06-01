class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> allPresent(1<<k,false);
        int N = s.size();
        if(k > s.size()){
            return false;
        }
        int initial = 0;
        for(int i=0;i<k;i++){
            int power = k-i-1;
            initial += ((s[i]-'0') << power);
        }
        allPresent[initial] = true;
        for(int i=k;i<N;i++){
            int maxPower = k-1;
            initial -= ((s[i-k]-'0') << maxPower);
            initial *= 2;
            initial += (s[i] - '0');
            allPresent[initial] = true;
        }
        for(bool x:allPresent){
            if(!x){
                return false;
            }
        }
        return true;
    }
};