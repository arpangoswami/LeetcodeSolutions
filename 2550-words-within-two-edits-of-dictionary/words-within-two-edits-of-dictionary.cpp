struct TrieNode {
    char ch;
    vector<TrieNode*> children;
    bool isTerminal;
    TrieNode(char ch){
        this->ch = ch;
        children.resize(26);
        for(int i=0;i<26;i++){
            this->children[i] = nullptr;
        }
        this->isTerminal = false;
    }
};
void insertWord(string &s, TrieNode *root){
    TrieNode* node = root;
    for(char &ch:s){
        if(!(node->children[ch - 'a'])){
            node->children[ch - 'a'] = new TrieNode(ch);
        }
        node = node->children[ch - 'a'];
    }
    node->isTerminal = true;
}
bool searchWord(TrieNode *root,string &s,int idx,int changesRemaining){
    if(idx >= s.size()){
        return root->isTerminal;
    }
    bool ans = false;
    for(int i=0;i<26;i++){
        if(!(root->children[i])){
            continue;
        }
        if(root->children[i]->ch == s[idx]){
            ans |= searchWord(root->children[i], s, idx+1, changesRemaining);
        }else if(changesRemaining > 0){
            ans |= searchWord(root->children[i], s, idx+1, changesRemaining - 1);
        }
    }
    return ans;
}
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        TrieNode *root = new TrieNode('\0');
        for(string &s:dictionary){
            insertWord(s, root);
        }
        vector<string> ans;
        for(string &s:queries){
            if(searchWord(root, s, 0, 2)){
                ans.push_back(s);
            }
        }
        return ans;
    }
};