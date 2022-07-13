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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> sol;
        vector<int> temp;
        while(!q.empty()){
            TreeNode *ft = q.front();
            q.pop();
            if(ft == nullptr){
                sol.push_back(temp);
                if(!q.empty()){
                    temp.clear();
                    q.push(nullptr);
                }
            }else{
                temp.push_back(ft->val);
                if(ft->left){
                    q.push(ft->left);
                }
                if(ft->right){
                    q.push(ft->right);
                }
            }            
        }
        return sol;
    }
};