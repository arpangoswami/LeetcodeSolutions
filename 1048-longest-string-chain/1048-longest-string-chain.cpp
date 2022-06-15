// class Solution {
//     bool isPredecessor(string parent,string child){
//         if(parent.size() + 1 != child.size()){
//             return false;
//         }
//         int ptr = 0,N = child.size(),skip = 0;
//         for(int i=0;i<N;i++){
//             if(ptr == parent.size() && skip == 0){
//                 return true;
//             }
//             if(child[i] != parent[ptr]){
//                 if(skip == 1){
//                     return false;
//                 }else{
//                     skip++;
//                 }
//             }else{
//                 ptr++;
//             }
//         }
//         return true;
//     }
// public:
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(),words.end(),[](string &s1,string &s2){
//             return s1.size() < s2.size();
//         });
//         int n = words.size();
//         vector<int> dp(n,1);
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(1+dp[j] > dp[i] && isPredecessor(words[j],words[i])){
//                     //cout<<"parent: "<<words[j]<<" child: "<<words[i]<<"\n";
//                     dp[i] = 1+dp[j];
//                 }
//             }
//         }
//         //cout<<isPredecessor("a","ba")<<"\n";
//         //for(int i=0;i<n;i++){
//             //cout<<dp[i]<<" "<<words[i]<<"\n";
//         //}
//         return *max_element(dp.begin(),dp.end());
//     }
// };

class Solution {
public:
    bool isPredecessor(const string &word1,const string &word2){
        deque<char> dq1,dq2;
        for(char c:word1){
            dq1.push_back(c);
        }
        for(char c:word2){
            dq2.push_back(c);
        }
        while(!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()){
            dq1.pop_front();
            dq2.pop_front();
        }
        while(!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()){
            dq1.pop_back();
            dq2.pop_back();
        }
        return dq1.empty() && dq2.size() == 1;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &word1,string &word2){
           if(word1.size() == word2.size()){
               return word1 < word2;
           } 
            return word1.size() < word2.size();
        });
        int n = words.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[j].size() + 1 != words[i].size()){
                    continue;
                }
                if(1+dp[j] > dp[i] && isPredecessor(words[j],words[i])){
                    dp[i] = 1 + dp[j];
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};