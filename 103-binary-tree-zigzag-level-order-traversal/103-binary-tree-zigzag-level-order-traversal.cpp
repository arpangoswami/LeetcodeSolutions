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
typedef pair<TreeNode*,int> pti;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<pti> q;
        q.push({root,0});
        int currLevel = 0;
        bool flag = true;
        vector<vector<int>> ans;
        vector<int> v;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(lvl > currLevel){
                if(currLevel % 2 == 1){
                    reverse(v.begin(),v.end());
                }
                ans.push_back(v);
                currLevel = lvl;
                v.clear();
            }
            v.push_back(node->val);
            if(node->left){
                q.push({node->left,1+lvl});
            }
            if(node->right){
                q.push({node->right,1+lvl});
            }
        }
        if(currLevel % 2 == 1){
            reverse(v.begin(),v.end());
        }
        ans.push_back(v);
        return ans;
    }
};