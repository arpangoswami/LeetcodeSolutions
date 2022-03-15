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
    TreeNode *makeTree(vector<pair<int,int>> &nodes,int &idx){
        TreeNode *root = new TreeNode(nodes[idx].first);
        int original = idx;
        idx++;
        if(idx == nodes.size()){
            return root;
        }
        if(idx < nodes.size() && nodes[idx].second == (nodes[original].second)+1){
            root->left = makeTree(nodes,idx);
        }
        if(idx < nodes.size() && nodes[idx].second == (nodes[original].second)+1){
            root->right = makeTree(nodes,idx);
        }
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        istringstream iss(traversal);
        int cnt = 0;
        vector<pair<int,int>> nodes;
        while(!iss.eof()){
            if(iss.peek() == '-'){
                while(iss.peek() == '-'){
                    char c;
                    iss >> c;
                    cnt++;
                }
            }else{
                int num;
                iss >> num;
                nodes.push_back({num,cnt});
                cnt = 0;
            }
        }
        // for(auto x:nodes){
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        int idx = 0;
        return makeTree(nodes,idx);
    }
};