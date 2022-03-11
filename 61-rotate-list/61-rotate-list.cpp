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
    int getLength(ListNode *head){
        ListNode *curr = head;
        int ans = 0;
        while(curr){
            ans++;
            curr = curr->next;
        }
        return ans;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        int length = getLength(head);
        k = k%length;
        if(k == 0){
            return head;
        }
        k++;
        int number = 1;
        ListNode *second = head;
        while(number < k){
            number++;
            second = second->next;
        }
        ListNode* first = head;
        while(second && second->next){
            first = first->next;
            second = second->next;
        }
        ListNode *ans = first->next;
        first->next = nullptr;
        second->next = head;
        return ans;
    }
};