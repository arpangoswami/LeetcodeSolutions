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
typedef long long ll;
class Solution {
public:
    bool isValidBST(TreeNode *root,ll low,ll high){
        if(!root){
            return true;
        }
        return root->val >= low && root->val <= high && isValidBST(root->left,low,(ll)root->val-1LL) && isValidBST(root->right,(ll)root->val+1LL,high);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,INT_MIN,INT_MAX);
    }
};