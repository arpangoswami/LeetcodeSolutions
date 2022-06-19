struct TrieNode{
    set<string> wordsInserted;
    vector<TrieNode*> children;
    char ch;
    bool isTerminal;
    TrieNode(char _ch){
        ch = _ch;
        children.resize(26,nullptr);
        isTerminal = false;
    }
};
class Solution {
    void addWord(string &x,TrieNode *root){
        TrieNode *curr = root;
        for(char c:x){
            if(curr->children[c-'a'] == nullptr){
                curr->children[c-'a'] = new TrieNode(c);
            }
            curr = curr->children[c-'a'];
            curr->wordsInserted.insert(x);
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode *root = new TrieNode('\0');
        for(string x:products){
            addWord(x,root);
        }
        TrieNode *curr = root;
        vector<vector<string>> ans;
        int N = searchWord.size();
        for(int i=0;i<N;i++){
            if(!curr->children[searchWord[i]-'a']){
                for(int j=i;j<N;j++){
                    ans.push_back({});
                }
                return ans;
            }else{
                curr = curr->children[searchWord[i] - 'a'];
                vector<string> toPush;
                for(string x:curr->wordsInserted){
                    toPush.push_back(x);
                    if(toPush.size() == 3){
                        break;
                    }
                }
                ans.push_back(toPush);
            }
            
        }
        return ans;
    }
};