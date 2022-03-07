struct TrieNode{
    set<string> wordsWithCommonPrefix;
    vector<TrieNode*> children;
    bool isTerminal;
    TrieNode(){
        children.resize(26,nullptr);
    }
};
class Solution {
    void insert(TrieNode* root,string &x){
        TrieNode *curr = root;
        for(char c:x){
            if(!curr->children[c-'a']){
                curr->children[c-'a'] = new TrieNode();
            }
            (curr->wordsWithCommonPrefix).insert(x);
            curr = curr->children[c-'a'];
        }
        curr->isTerminal = true;
        (curr->wordsWithCommonPrefix).insert(x);
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        for(string x:products){
            insert(root,x);
        }
        vector<vector<string>> ans;
        TrieNode *curr = root;
        for(char c:searchWord){
            if(!curr){
                ans.push_back({});
                continue;
            }
            curr = curr->children[c-'a'];
            if(!curr){
                ans.push_back({});
                continue;
            }
            const set<string> &vals = (curr->wordsWithCommonPrefix);
            vector<string> toPush;
            auto it = vals.begin();
            while(it != vals.end() && toPush.size() < 3){
                toPush.push_back(*it);
                it++;
            }
            ans.push_back(toPush);
        }
        return ans;
    }
};