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
typedef pair<TreeNode*,TreeNode*> pii;
class Solution {
    pii flattenTree(TreeNode* root){
        if(!root){
            return {nullptr,nullptr};
        }
        else if(!(root->left) && !(root->right)){
            return {root,root};
        }
        else if(!(root->left) && (root->right)){
            pii p1 = flattenTree(root->right);
            root->right = p1.first;
            return {root,p1.second};
        }else if((root->left) && !(root->right)){
            pii p1 = flattenTree(root->left);
            root->left = nullptr;
            root->right = p1.first;
            return {root,p1.second};
        }
        pii p1 = flattenTree(root->left);
        pii p2 = flattenTree(root->right);
        root->left = nullptr;
        root->right = p1.first;
        (p1.second)->right = p2.first;
        return {root,p2.second};
    }
public:
    void flatten(TreeNode* root) {
        pii p = flattenTree(root);
        root = p.first;
    }
};