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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyFirstHead = new ListNode(-101),*dummyFirstTail = dummyFirstHead;
        ListNode *dummySecondHead = new ListNode(-101),*dummySecondTail = dummySecondHead;
        ListNode *curr = head;
        while(curr){
            if(curr->val < x){
                dummyFirstTail->next = curr;
                dummyFirstTail = dummyFirstTail->next;
            }else{
                dummySecondTail->next = curr;
                dummySecondTail = dummySecondTail->next;
            }
            curr = curr->next;
        }
        dummyFirstTail->next = nullptr;
        dummySecondTail->next = nullptr;
        if(dummySecondTail == dummySecondHead){
            ListNode *ans = dummyFirstHead->next;
            dummyFirstHead->next = nullptr;
            delete dummyFirstHead;
            return ans;
        }
        if(dummyFirstTail == dummyFirstHead){
            ListNode *ans = dummySecondHead->next;
            dummySecondHead->next = nullptr;
            delete dummySecondHead;
            return ans;
        }
        ListNode *secondPart = dummySecondHead->next;
        ListNode *firstPart = dummyFirstHead->next;
        dummyFirstHead->next = nullptr;
        dummySecondHead->next = nullptr;
        dummyFirstTail->next = secondPart;
        delete dummyFirstHead;
        delete dummySecondHead;
        return firstPart;
    }
};