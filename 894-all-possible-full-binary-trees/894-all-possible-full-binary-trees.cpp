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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0){
            return {};
        }
        vector<TreeNode*> ans;
        if(n == 1){
            TreeNode *root = new TreeNode();
            ans.push_back(root);
            return ans;
        }
        int remaining = n-1;
        for(int i=1;i<remaining;i+=2){
            vector<TreeNode*> leftChilds = allPossibleFBT(i);
            vector<TreeNode*> rightChilds = allPossibleFBT(remaining-i);
            int m = leftChilds.size(),p = rightChilds.size();
            for(int j=0;j<m;j++){
                for(int k=0;k<p;k++){
                    TreeNode *root = new TreeNode(0,leftChilds[j],rightChilds[k]);
                    ans.push_back(root);
                }
            }
            
        }
        return ans;
    }
};