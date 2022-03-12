// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };
// */

// class Solution {
//     Node* joinLists(Node* head,Node* headNew){
//         Node *dummyHead = new Node(-1);
//         Node *dummyOther = new Node(-1);
//         Node *tail = dummyHead,*tailOther = dummyOther;
//         Node *curr = head,*other = headNew;
//         while(curr){
//             tail->next = tailOther;
//             ta
//             curr = curr->next;
//             other = other->next;
//         }
//     }
// public:
//     Node* copyRandomList(Node* head) {
//         if(!head){
//             return head;
//         }
//         Node *curr = head;
//         Node *headNew = new Node(curr->val);
//         curr = curr->next;
//         Node *tailNew = headNew;
//         while(curr){
//             tailNew->next = new Node(curr->val);
//             curr = curr->next;
//             tailNew = tailNew->next;
//         }
//         Node *combinedHead = joinLists(head,headNew);
//         pair<Node*,Node*> ans = separate(combinedHead);
//         return ans.second;
//     }
// };
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        Node *curr1 = head;
        
        //Making deep copies with help of next pointe
        Node *head2 = new Node(curr1->val);
        Node *curr2 = head2;
        curr1 = curr1->next;
        while(curr1){
            curr2->next = new Node(curr1->val);
            curr2 = curr2->next;
            curr1 = curr1->next;
        }
        curr2->next = nullptr;
        
        //Interleaving old and new lists
        curr2 = head2;
        curr1 = head;
        while(curr1){
            Node *temp1 = curr1->next,*temp2 = curr2->next;
            curr1->next = curr2;
            curr2->next = temp1;
            curr1 = temp1;
            curr2 = temp2;
        }
        
        //using old list for random pointer
        curr1 = head;
        while(curr1){
            Node *temp = curr1->random;
            if(temp){
                curr1->next->random = temp->next;
            }else{
                curr1->next->random = nullptr;
            }
            curr1 = curr1->next->next;
        }
        
        //separating the interleaved lists
        head2 = head->next;
        Node *tail2 = head2;
        Node *tail1 = head;
        if(tail2->next == nullptr){
            tail1->next = nullptr;
            return head2;
        }
        curr1 = tail2->next;
        curr2 = curr1->next;
        while(curr1){
            tail1->next = curr1;
            tail2->next = curr2;
            curr1 = curr1->next->next;
            if(curr1)
                curr2 = curr1->next;
            tail1 = tail1->next;
            tail2 = tail2->next;
        }
        tail1->next = nullptr;
        tail2->next = nullptr;
        return head2;
    }
};