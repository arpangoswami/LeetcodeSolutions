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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = 0,cntB = 0;
        ListNode *currA = headA,*currB = headB;
        while(currA){
            cntA++;
            currA = currA->next;
        }
        while(currB){
            cntB++;
            currB = currB->next;
        }
        currA = headA;
        currB = headB;
        if(cntA > cntB){
            int diff = cntA - cntB;
            while(diff > 0){
                currA = currA->next;
                diff--;
            }
        }else{
            int diff = cntB - cntA;
            while(diff > 0){
                currB = currB->next;
                diff--;
            }
        }
        while(currA && currB && currA != currB){
            currA = currA->next;
            currB = currB->next;
        }
        if(!currB){
            return NULL;
        }
        return currA;
    }
};