struct TrieNode{
    char ch;
    vector<TrieNode*>children;
    bool isTerminal;
    TrieNode(char ch){
        this->ch = ch;
        children.resize(26);
        fill(children.begin(),children.end(),nullptr);
    }
    void addWord(string &s){
        TrieNode *root = this;
        for(char &ch:s){
            if(root->children[ch-'a'] == nullptr){
                root->children[ch-'a'] = new TrieNode(ch);
            }
            root = root->children[ch-'a'];
        }
        root->isTerminal = true;
    }
};
class Solution {
    void findMinimumLength(int &ans,int currlength,TrieNode *root){
        int children = 0;
        for(TrieNode *curr:root->children){
            if(curr){
                children++;
                findMinimumLength(ans,currlength+1,curr);
            }
        }
        if(children == 0){
            ans += (currlength+1);
        }
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode *root = new TrieNode('\0');
        for(string s:words){
            reverse(s.begin(),s.end());
            root->addWord(s);
        }
        int ans = 0;
        findMinimumLength(ans,0,root);
        return ans;
    }
};