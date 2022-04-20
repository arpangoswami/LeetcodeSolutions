/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> tree;
    void addToStack(TreeNode* node){
        while(node){
            tree.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        addToStack(root);
    }
    
    int next() {
        TreeNode* node = tree.top();
        tree.pop();
        addToStack(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !tree.empty();
    }
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */