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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        ListNode *head = new ListNode(l1->val + l2->val);
        int carry = (head->val)/10;
        head->val = (head->val)%10;
        ListNode *tail = head,*curr1 = l1->next,*curr2 = l2->next;
        while(curr1 && curr2){
            tail->next = new ListNode(carry+curr1->val+curr2->val);
            tail = tail->next;
            carry = (tail->val)/10;
            tail->val %= 10;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1){
            tail->next = new ListNode(carry+curr1->val);
            tail = tail->next;
            carry = (tail->val)/10;
            tail->val %= 10;
            curr1 = curr1->next;
            //curr2 = curr2->next;
        }
        while(curr2){
            tail->next = new ListNode(carry+curr2->val);
            tail = tail->next;
            carry = (tail->val)/10;
            tail->val %= 10;
            //curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if(carry){
            tail->next = new ListNode(carry);
            tail = tail->next;
            carry = 0;
        }
        return head;
    }
};