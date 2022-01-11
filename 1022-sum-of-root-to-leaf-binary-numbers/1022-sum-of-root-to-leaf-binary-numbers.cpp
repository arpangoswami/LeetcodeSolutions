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
    void allPathsToLeaf(TreeNode* root,int sum,int &totalSum){
        if(!root){
            return;
        }
        if(!(root->left) && !(root->right)){
            int tillNow = sum*2 + root->val;
            totalSum += tillNow;
        }else{
            allPathsToLeaf(root->left,2*sum+root->val,totalSum);
            allPathsToLeaf(root->right,2*sum+root->val,totalSum);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        allPathsToLeaf(root,0,ans);
        return ans;
    }
};