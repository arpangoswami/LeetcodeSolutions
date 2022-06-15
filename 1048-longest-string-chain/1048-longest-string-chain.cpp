class Solution {
    bool isPredecessor(string &parent,string &child){
        if(parent.size() + 1 != child.size()){
            return false;
        }
        int ptr = 0,N = child.size(),skip = 0;
        for(int i=0;i<N;i++){
            if(ptr == parent.size() && skip == 0){
                return true;
            }
            if(child[i] != parent[ptr]){
                if(skip == 1){
                    return false;
                }else{
                    skip++;
                }
            }else{
                ptr++;
            }
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &s1,string &s2){
            return s1.size() < s2.size();
        });
        int n = words.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(1+dp[j] > dp[i] && isPredecessor(words[j],words[i])){
                    dp[i] = 1+dp[j];
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};