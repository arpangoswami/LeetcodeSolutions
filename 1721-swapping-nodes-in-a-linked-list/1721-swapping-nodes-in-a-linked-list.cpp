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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !(head->next)){
            return head;
        }
        ListNode *second = head;
        int ptr = 1;
        ListNode *first = head;
        while(ptr <= k){
            second = second->next;
            ptr++;
            if(ptr == k){
                first = second;
            }
        }
        ListNode *temp = head;
        while(second){
            temp = temp->next;
            second = second->next;
        }
        swap(first->val,temp->val);
        return head;
    }
};