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
    void findMaxDepth(TreeNode* root,int &maxDepth,int level){
        if(!root){
            return;
        }
        maxDepth = max(maxDepth,level);
        findMaxDepth(root->left,maxDepth,level+1);
        findMaxDepth(root->right,maxDepth,level+1);
    }
    void dfs(TreeNode *root,const int &maxDepth,int &ans,int level){
        if(!root){
            return;
        }
        if(level == maxDepth){
            ans += root->val;
        }
        dfs(root->left,maxDepth,ans,level+1);
        dfs(root->right,maxDepth,ans,level+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = 0;
        findMaxDepth(root,maxDepth,0);
        int ans = 0;
        dfs(root,maxDepth,ans,0);
        return ans;
    }
};