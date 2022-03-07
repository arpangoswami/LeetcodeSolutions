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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *tail = dummyHead,*curr1 = list1,*curr2 = list2;
        while(curr1 && curr2){
            if(curr1->val < curr2->val){
                tail->next = curr1;
                ListNode *temp = curr1->next;
                curr1->next = nullptr;
                curr1 = temp;
            }else{
                tail->next = curr2;
                ListNode *temp = curr2->next;
                curr2->next = nullptr;
                curr2 = temp;
            }
            tail = tail->next;
        }
        while(curr1){
            tail->next = curr1;
            ListNode *temp = curr1->next;
            curr1->next = nullptr;
            curr1 = temp;
            tail = tail->next;
        }
        while(curr2){
            tail->next = curr2;
            ListNode *temp = curr2->next;
            curr2->next = nullptr;
            curr2 = temp;
            tail = tail->next;
        }
        ListNode *ans = dummyHead->next;
        dummyHead->next = nullptr;
        delete dummyHead;
        return ans;
    }
};