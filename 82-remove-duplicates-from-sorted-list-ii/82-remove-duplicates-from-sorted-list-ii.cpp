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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)){
            return head;
        }
        ListNode *dummyHead = new ListNode(-101);
        ListNode *curr = head;
        ListNode *tail = dummyHead;
        while(curr){
            int count = 0;
            ListNode *runner = curr;
            while(runner && runner->val == curr->val){
                count++;
                runner = runner->next;
            }
            if(count == 1){
                tail->next = curr;
                tail = tail->next;
            }
            tail->next = nullptr;
            curr = runner;
        }
        ListNode *ans = dummyHead->next;
        dummyHead->next = nullptr;
        delete dummyHead;
        return ans;
    }
};