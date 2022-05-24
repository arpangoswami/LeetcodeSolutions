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
struct TreeData {
    int sum;
    bool isBST;
    int maxValue;
    int minValue;
    TreeData(int sum,bool isBST,int maxValue,int minValue){
        this->sum = sum;
        this->isBST = isBST;
        this->maxValue = maxValue;
        this->minValue = minValue;
    }
};
class Solution {
    bool isBstTree(TreeNode *root,TreeData &leftData,TreeData &rightData){
        return (leftData.isBST && rightData.isBST && root->val > leftData.maxValue && root->val < rightData.minValue);
    }
    TreeData solve(TreeNode *root,int &maxSum){
        if(!root){
            return TreeData(0,true,INT_MIN,INT_MAX);
        }
        TreeData leftData = solve(root->left,maxSum);
        TreeData rightData = solve(root->right,maxSum);
        if(isBstTree(root,leftData,rightData)){
            int sum = leftData.sum+rightData.sum+root->val;
            maxSum = max(maxSum,sum);
            return TreeData(sum,true,max(root->val,rightData.maxValue),min(root->val,leftData.minValue));
        }
        return TreeData(INT_MIN,false,INT_MIN,INT_MAX);
    }
public:
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return sum;
    }
};