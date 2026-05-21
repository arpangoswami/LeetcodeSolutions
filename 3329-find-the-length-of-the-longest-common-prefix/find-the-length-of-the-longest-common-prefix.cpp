struct TrieNode {
    vector<TrieNode*> children;
    bool isTerminal;
    TrieNode(){
        this->children.resize(10);
        fill(this->children.begin(),this->children.end(), nullptr);
        this->isTerminal = false;
    }
};
class Solution {
    void addWord(int x, TrieNode* root){
        TrieNode* curr = root;
        string num = to_string(x);
        for(char &ch:num){
            if(!curr->children[ch - '0']){
                curr->children[ch - '0'] = new TrieNode();
            }
            curr = curr->children[ch - '0'];
        }
        curr->isTerminal = true;
    }
    int getLongestPrefix(int x, TrieNode *root){
        TrieNode *curr = root;
        string num = to_string(x);
        int ans = 0;
        for(char &ch:num){
            if(curr->children[ch - '0']){
                ans++;
                curr = curr->children[ch - '0'];
            }else{
                return ans;
            }
        }
        return ans;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode *root = new TrieNode();
        for(int &x:arr1){
            addWord(x, root);
        }
        int ans = 0;
        for(int &x:arr2){
            ans = max(ans, getLongestPrefix(x, root));
        }
        return ans;
    }
};