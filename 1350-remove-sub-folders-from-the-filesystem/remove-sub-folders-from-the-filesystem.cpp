// struct TrieNode {
//     unordered_map<string,TrieNode*> children;
//     string value;
//     bool isTerminal;
//     TrieNode(string s){
//         this->value = s;
//         this->isTerminal = false;
//     }
// };
// class Solution {
//     void addStrings(TrieNode *root, vector<string> &subs){
//         TrieNode *node = root;
//         for(string &x:subs){
//             if(!((node->children).count(x))){
//                 TrieNode *childNode = new TrieNode(x);
//                 node->children[x] = childNode;
//             }
//             node = node->children[x];
//         }
//         node->isTerminal = true;
//     }
//     void removeLetters(string &s, int len){
//         assert (s.size() >= len);
//         while(len > 0){
//             s.pop_back();
//             len--;
//         }
//     }
//     void dfs(vector<string> &ans, TrieNode *node, string &currPath){
//         currPath += node->value;
//         int len = (node->value).size();
//         if(node->isTerminal){
//             ans.push_back(currPath);
//         }else{
//             for(auto it:node->children){
//                 currPath.push_back('/');
//                 dfs(ans, it.second, currPath);
//             }
//         }
//         removeLetters(currPath, len+1);
//     }
// public:
//     vector<string> removeSubfolders(vector<string>& folder) {
//         TrieNode *root = new TrieNode("");
//         for(string &s:folder){
//             istringstream iss(s);
//             string temp;
//             vector<string> subs;
//             while(getline(iss, temp, '/')){
//                 if(temp.size() > 0){
//                     subs.push_back(temp);
//                 }
//             }
//             addStrings(root, subs);
//         }
        
//         vector<string> ans;
//         for(auto it:root->children){
//             string currPath = "/";
//             dfs(ans, it.second, currPath);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    bool isPrefix(string& a, string &b) {
       if (b.size() > a.size()) {
           return false;
       } 
        
       for  (int i = 0; i < b.size(); i++) {
           if (a[i] != b[i]) {
               return false;
           }
       } 
        
       return a.size() == b.size() || a[b.size()] == '/';
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        
        sort(folder.begin(), folder.end());
        
        for (string& f : folder) {
            if (result.empty() || !isPrefix(f, result.back())) {
                result.push_back(f);
            }
        }
        
        return result;
    }
};

static const int init = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();