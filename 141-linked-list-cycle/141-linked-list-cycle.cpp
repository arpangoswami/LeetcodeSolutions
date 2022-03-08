/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !(head->next)){
            return false;
        }
        ListNode *first = head,*second = head->next;
        while(second && second->next && first != second){
            first = first->next;
            second = second->next->next;
        }
        return first == second;
    }
};