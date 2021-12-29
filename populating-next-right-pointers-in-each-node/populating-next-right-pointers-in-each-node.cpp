class Solution {
public:
    typedef pair<Node*,int> pii;
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        Node *rt = nullptr;
        queue<pii> Q;
        Q.push({root,0});
        int lvl = 0;
        while(!Q.empty()){
            pii temp = Q.front();
            Q.pop();
            Node *t2 = temp.first;
            int level = temp.second;
            if(level > lvl){
                rt = nullptr;
                lvl = level;
            }
            t2->next = rt;
            rt = t2;
            if(t2->right){
                Q.push({t2->right,temp.second+1});
            }
            if(t2->left){
                Q.push({t2->left,temp.second+1});
            }
        }
        return root;
    }
};