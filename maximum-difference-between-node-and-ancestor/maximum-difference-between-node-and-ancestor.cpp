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
    int maxAncestorDiff(TreeNode* root,int maxVal,int minVal){
        if(!root){
            return 0;
        }
        int v1 = maxAncestorDiff(root->left,max(maxVal,root->val),min(minVal,root->val)),
        v2 = maxAncestorDiff(root->right,max(maxVal,root->val),min(minVal,root->val)),v3 = abs(root->val - maxVal),v4 = abs(root->val - minVal);
        return max({v1,v2,v3,v4});
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        return max(maxAncestorDiff(root->left,root->val,root->val),
                   maxAncestorDiff(root->right,root->val,root->val));
    }
};