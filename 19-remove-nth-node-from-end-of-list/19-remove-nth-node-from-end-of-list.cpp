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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(-1,head);
        n++;
        ListNode *second = dummyHead;
        int ptr = 1;
        while(ptr <= n){
            second = second->next;
            ptr++;
        }
        ListNode *first = dummyHead;
        while(second){
            first = first->next;
            second = second->next;
        }
        ListNode *nextPart = first->next->next;
        ListNode *toDel = first->next;
        toDel->next = nullptr;
        first->next = nextPart;
        delete toDel;
        ListNode *ans = dummyHead->next;
        dummyHead->next = nullptr;
        delete dummyHead;
        return ans;
    }
};