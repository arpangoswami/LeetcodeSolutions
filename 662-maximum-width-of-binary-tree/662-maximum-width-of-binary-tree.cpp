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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,ll>> q;
        q.push({root,1});
        ll ans = 0;
        while(!q.empty()){
            ll size_of_queue = q.size();
            ans = max(q.back().second - q.front().second + 1,ans);
            ll start = q.front().second;
            while(size_of_queue > 0){
                TreeNode* node = q.front().first;
                ll level = q.front().second - start;
                q.pop();
                if(node->left){
                    q.push({node->left,2*level});
                }
                if(node->right){
                    q.push({node->right,2*level+1});
                }
                size_of_queue--;
            }
        }
        return ans;
    }
};