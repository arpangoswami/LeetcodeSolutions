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
    bool isLeaf(TreeNode* root){
        if(!root || root->left || root->right){
            return false;
        }
        return true;
    }
    void addLeftBoundary(TreeNode* root,vector<int> &ans){
        TreeNode *curr = root->left;
        while(curr){
            if(!isLeaf(curr))
                ans.push_back(curr->val);
            if(curr->left){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
    }
    void addRightBoundary(TreeNode *root,vector<int> &ans){
        vector<int> temp;
        TreeNode *curr = root->right;
        while(curr){
            if(!isLeaf(curr))
                temp.push_back(curr->val);
            if(curr->right){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        while(temp.size() > 0){
            ans.push_back(temp.back());
            temp.pop_back();
        }
    }
    void addLeaves(TreeNode* root,vector<int> &ans){
        if(!root){
            return;
        }
        if(isLeaf(root)){
            ans.push_back(root->val);
        }
        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        if(!isLeaf(root)){
            ans.push_back(root->val);
        }
        addLeftBoundary(root,ans);
        addLeaves(root,ans);
        addRightBoundary(root,ans);
        return ans;
    }
};