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
struct myCmp{
    bool operator()(ListNode* l1,ListNode* l2){
        return l1->val > l2->val;
    }  
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(-10001);
        ListNode *tail = dummyHead;
        priority_queue<ListNode*,vector<ListNode*>,myCmp> pq;
        for(ListNode* head:lists){
            if(head){
                pq.push(head);
            }
        }
        while(!pq.empty()){
            ListNode* lowest = pq.top();
            pq.pop();
            ListNode* lowestNext = lowest->next;
            lowest->next = nullptr;
            tail->next = lowest;
            tail = tail->next;
            if(lowestNext){
                pq.push(lowestNext);
            }
        }
        ListNode *head = dummyHead->next;
        dummyHead->next = nullptr;
        delete dummyHead;
        return head;
    }
};