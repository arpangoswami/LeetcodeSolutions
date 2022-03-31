/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    int calSum(vector<vector<int>> &pref,int tlx,int tly,int brx,int bry){
        int ans = pref[brx][bry];
        if(tlx > 0){
            ans -= pref[tlx-1][bry];
        }
        if(tly > 0){
            ans -= pref[brx][tly-1];
        }
        if(tlx > 0 && tly > 0){
            ans += pref[tlx-1][tly-1];
        }
        return ans;
    }
    Node *constructTree(vector<vector<int>> &pref,int tlx,int tly,int brx,int bry){
        int number = (brx - tlx + 1) * (bry - tly + 1);
        int sum = calSum(pref,tlx,tly,brx,bry);
        if(number == sum || sum == 0){
            return new Node(bool(sum),true);
        }
        int midX = (tlx+brx)/2,midY = (tly+bry)/2;
        Node *lTopChild = constructTree(pref,tlx,tly,midX,midY),*rTopChild = constructTree(pref,tlx,midY+1,midX,bry),
        *lBotChild = constructTree(pref,midX+1,tly,brx,midY),*rBotChild = constructTree(pref,midX+1,midY+1,brx,bry);
        return new Node(true,false,lTopChild,rTopChild,lBotChild,rBotChild);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> prefSum(n,vector<int>(m));
        prefSum[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
            prefSum[i][0] = prefSum[i-1][0] + grid[i][0];
        }
        for(int j=1;j<m;j++){
            prefSum[0][j] = prefSum[0][j-1] + grid[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                prefSum[i][j] = prefSum[i-1][j] + prefSum[i][j-1] + grid[i][j] - prefSum[i-1][j-1];
            }
        }
        return constructTree(prefSum,0,0,n-1,n-1);
    }
};