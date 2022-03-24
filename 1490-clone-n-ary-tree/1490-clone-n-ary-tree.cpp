/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(!root){
            return nullptr;
        }
        int N = root->children.size();
        Node* newRoot = new Node(root->val);
        newRoot->children.resize(N);
        for(int i=0;i<N;i++){
            Node* val = cloneTree(root->children[i]);
            newRoot->children[i] = val;
        }
        return newRoot;
    }
};