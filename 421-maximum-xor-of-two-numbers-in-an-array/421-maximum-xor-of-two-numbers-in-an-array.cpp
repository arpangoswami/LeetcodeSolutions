struct TrieNode{
    TrieNode *children[2];
    TrieNode(){
        this->children[0] = this->children[1] = nullptr;
    }
};
class Solution {
    void addNumber(TrieNode* root,int number){
        TrieNode *curr = root;
        for(int i=30;i>=0;i--){
            int bit = (number >> i)&1;
            if(curr->children[bit] == nullptr){
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }
    int findMaximum(TrieNode* root,int number){
        int ans = 0;
        TrieNode* curr = root;
        for(int i=30;i>=0;i--){
            int bit = (number >> i)&1;
            if(curr->children[1^bit]){
                ans += (1 << i);
                curr = curr->children[1^bit];
            }else{
                curr = curr->children[bit];
            }
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        TrieNode *root = new TrieNode();
        addNumber(root,nums[0]);
        int ans = 0;
        for(int i=1;i<n;i++){
            ans = max(ans,findMaximum(root,nums[i]));
            addNumber(root,nums[i]);
        }
        return ans;
    }
};