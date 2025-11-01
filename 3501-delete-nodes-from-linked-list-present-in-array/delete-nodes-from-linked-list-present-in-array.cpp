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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;
        ListNode *nextPtr = dummy->next;
        while(nextPtr){
            ListNode *nextChild = nextPtr->next;
            if(st.count(nextPtr->val)){
                //cout << "deleting nextPtr: " << nextPtr->val << '\n';
                ListNode *toDelete = nextPtr;
                prev->next = nextChild;
                toDelete->next = nullptr;
                //delete toDelete;
            }else{
                prev = nextPtr;
            }
            //cout << "nextPtr value: " << nextPtr->val << '\n';
            nextPtr = nextChild;
        }
        ListNode *ans = dummy->next;
        dummy->next = nullptr;
        //delete dummy;
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();