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
    int findMaxSum(TreeNode* root,int &ans){
        if(root->left && root->right){
            int leftVal = findMaxSum(root->left,ans);
            int rightVal = findMaxSum(root->right,ans);
            ans = max({ans,leftVal+rightVal+root->val,root->val,leftVal+root->val,rightVal+root->val});
            return max({root->val,leftVal+root->val,rightVal+root->val});
        }else if(root->left){
            int leftVal = findMaxSum(root->left,ans);
            ans = max({ans,leftVal+root->val,root->val});
            return max(leftVal+root->val,root->val);
        }else if(root->right){
            int rightVal = findMaxSum(root->right,ans);
            ans = max({ans,rightVal+root->val,root->val});
            return max(rightVal+root->val,root->val);
        }
        ans = max(ans,root->val);
        return root->val;
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMaxSum(root,ans);
        return ans;
    }
};