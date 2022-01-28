struct TrieNode{
    vector<TrieNode*> children;
    bool isTerminal;
    TrieNode(){
        children.resize(26);
        fill(children.begin(),children.end(),nullptr);
        isTerminal = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for(char c:word){
            if(curr->children[c-'a'] == nullptr){
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isTerminal = true;
    }
    bool dfs(TrieNode* root,const string &word,int idx){
        if(idx == (int)word.size()){
            return root->isTerminal;
        }
        if(word[idx] == '.'){
            for(int i=0;i<26;i++){
                if(root->children[i] && dfs(root->children[i],word,idx+1)){
                    return true;
                }
            }
            return false;
        }
        if(root->children[word[idx]-'a']){
            return dfs(root->children[word[idx]-'a'],word,idx+1);
        }
        return false;
    }
    bool search(string word) {
        if(word[0] == '.'){
            for(int i=0;i<26;i++){
                if(root->children[i] && dfs(root->children[i],word,1)){
                    return true;
                }
            }
            return false;
        }
        if(root->children[word[0]-'a']){
            return dfs(root->children[word[0]-'a'],word,1);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */