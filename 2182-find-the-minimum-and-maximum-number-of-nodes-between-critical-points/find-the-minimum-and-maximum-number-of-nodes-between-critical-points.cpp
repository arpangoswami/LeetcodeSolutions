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
    bool isExtremeParent(ListNode *node){
        return (
            (node->next->val > node->val && node->next->val > node->next->next->val) || 
            (node->next->val < node->val && node->next->val < node->next->next->val)
        );
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int ptr = 0;
        int lastPtr = -1,firstPtr = -1,minDist = INT_MAX,maxDist = INT_MIN;
        for(ListNode *curr = head;curr->next->next != nullptr;curr = curr->next,ptr++){
            if(isExtremeParent(curr)){
                if(lastPtr != -1){
                    minDist = min(minDist, ptr - lastPtr);
                }else{
                    firstPtr = ptr;
                }
                lastPtr = ptr;
            }
        }
        if(minDist != INT_MAX){
            return {minDist,lastPtr - firstPtr};
        }
        return {-1,-1};
    }
};