/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    unordered_map<int,int> mp;
    int maxm;
    Solution(ListNode* head) {
        maxm = 0;
        ListNode *curr = head;
        while(curr){
            mp[maxm++] = curr->val;
            curr = curr->next;
        }
        srand(time(0));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return mp[rand()%maxm];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */