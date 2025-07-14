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
    int getDecimalValue(ListNode* head) {
        int n = 0;
        int pos = 1;
        int ans = 0;
        for(ListNode *curr=head;curr;n++,curr=curr->next){    
        }
        for(ListNode* curr=head;curr != nullptr;curr = curr->next,pos++){
            ans += curr->val * (1 << (n-pos));
        }
        return ans;
    }
};