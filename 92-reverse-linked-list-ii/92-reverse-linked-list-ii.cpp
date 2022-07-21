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
    pair<ListNode*,ListNode*> reverse(ListNode* head){
        ListNode *prev = nullptr,*curr = head,*originalHead = head;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return {prev,originalHead};
    }
    void print(ListNode* head){
        ListNode *curr = head;
        while(curr){
            cout<<curr->val<<" ";
            curr = curr->next;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head;
        ListNode *firstPartTail = nullptr;
        for(int i=1;i<left;++i){
            firstPartTail = curr;
            curr = curr->next;
        }
        ListNode *midPartHead = firstPartTail ? firstPartTail->next : head;
        //cout<<midPartHead->val<<"\n";
        for(int i=left;i<right;++i){
            curr = curr->next;
        }
        ListNode *midPartTail = curr;
        //cout<<midPartTail->val<<"\n";
        ListNode *thirdPartHead = curr->next;
        midPartTail->next = nullptr;
        pair<ListNode*,ListNode*> midPart = reverse(midPartHead);
        print(midPart.first);
        (midPart.second)->next = thirdPartHead;
        if(firstPartTail){
            firstPartTail->next = midPart.first;
            return head;        
        }
        return midPart.first;
    }
};