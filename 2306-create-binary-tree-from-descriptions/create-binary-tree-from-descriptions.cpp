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
    TreeNode *constructTree(map<int, vector<int>> &parent,int root){
        TreeNode *rootNode = new TreeNode(root);
        if(parent.count(root)){
            int firstChild = parent[root][0];
            int direction = parent[root][1];
            if(direction == 1){
                rootNode->left = constructTree(parent,firstChild);
            }else{
                rootNode->right = constructTree(parent,firstChild);
            }
            if(parent[root].size() > 2){
                int secondChild = parent[root][2];
                direction = parent[root][3];
                if(direction == 1){
                    rootNode->left = constructTree(parent,secondChild);
                }else{
                    rootNode->right = constructTree(parent,secondChild);
                }
            }
        }
        return rootNode;
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, vector<int>> parent;
        set<int> child;
        for(vector<int> &v:descriptions){
            parent[v[0]].push_back(v[1]);
            parent[v[0]].push_back(v[2]);
            child.insert(v[1]);
        }
        int root = -1;
        for(auto &it:parent){
            if(!child.count(it.first)){
                root = it.first;
                break;
            }
        }
        return constructTree(parent,root);

    }
};