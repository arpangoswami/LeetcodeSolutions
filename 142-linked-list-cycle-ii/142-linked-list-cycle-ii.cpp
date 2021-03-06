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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next)){
            return nullptr;
        }
        ListNode *first = head->next,*second = head->next->next;
        while(second && second->next && first != second){
            first = first->next;
            second = second->next->next;
        }
        if(first != second){
            return nullptr;
        }
        first = head;
        while(first != second){
            first = first->next;
            second = second->next;
        }
        return first;
    }
};