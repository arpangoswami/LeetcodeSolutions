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
    pair<int,int> getSumNumber(TreeNode *root,int &ans){
        if(!root){
            return {0,0};
        }
        pair<int,int> leftProperties = getSumNumber(root->left,ans);
        pair<int,int> rightProperties = getSumNumber(root->right,ans);
        int nodes = leftProperties.second + rightProperties.second + 1;
        int sum = leftProperties.first + rightProperties.first + root->val;
        int desiredAvg = sum/nodes;
        if(desiredAvg == root->val){
            ans++;
        }
        return {sum, nodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        getSumNumber(root, ans);
        return ans;
    }
};