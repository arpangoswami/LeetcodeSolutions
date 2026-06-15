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
    ListNode* deleteMiddle(ListNode* head) {
        if((head->next) == nullptr){
            return nullptr;
        }
        ListNode *second = head->next,*first = head;
        while(second && second->next && second->next->next){
            second = second->next->next;
            first = first->next;
        }
        ListNode *nextLink = first->next->next;
        ListNode *toDelete = first->next;
        delete toDelete;
        first->next = nextLink;
        return head;
    }
};