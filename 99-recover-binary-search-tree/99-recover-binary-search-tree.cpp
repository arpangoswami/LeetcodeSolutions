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
public:
    void inorderTrav(TreeNode* root,TreeNode* &firstVal,TreeNode* &secondVal,TreeNode* &prev){
        if(!root){
            return;
        }
        inorderTrav(root->left,firstVal,secondVal,prev);
        if(prev && root->val < prev->val){
            if(!firstVal){
                firstVal = prev;
            }
            secondVal = root;
        }
        prev = root;
        inorderTrav(root->right,firstVal,secondVal,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* firstVal = nullptr, *secondVal = nullptr, *prev = nullptr;
        inorderTrav(root,firstVal,secondVal,prev);
        swap(firstVal->val,secondVal->val);
    }
};