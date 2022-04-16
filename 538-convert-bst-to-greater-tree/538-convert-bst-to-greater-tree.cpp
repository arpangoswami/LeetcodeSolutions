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
class Solution {
    void modifyBST(TreeNode* root,int &greater){
        if(!root){
            return;
        }
        modifyBST(root->right,greater);
        root->val += greater;
        greater = root->val;
        modifyBST(root->left,greater);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int greater = 0;
        modifyBST(root,greater);
        return root;
    }
};