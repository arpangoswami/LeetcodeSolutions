// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node* reverse(Node *head){
        Node *prevPtr = nullptr,*curr = head;
        while(curr){
            Node* tempNext = curr->next;
            curr->next = prevPtr;
            prevPtr = curr;
            curr = tempNext;
        }
        return prevPtr;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first),second = reverse(second);
        Node* dummy = new Node(-1);
        Node *tail = dummy;
        Node *curr1 = first,*curr2 = second;
        int carry = 0;
        while(curr1 && curr2){
            int sum = curr1->data + curr2->data + carry;
            tail->next = new Node(sum%10);
            carry = sum / 10;
            tail = tail->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1){
            int sum = curr1->data + carry;
            tail->next = new Node(sum%10);
            carry = sum / 10;
            tail = tail->next;
            curr1 = curr1->next;
        }
        while(curr2){
            int sum = curr2->data + carry;
            tail->next = new Node(sum%10);
            carry = sum / 10;
            tail = tail->next;
            curr2 = curr2->next;
        }
        if(carry){
            tail->next = new Node(carry);
        }
        first = reverse(first),second = reverse(second);
        Node* ans = dummy->next;
        dummy->next = nullptr;
        delete dummy;
        ans = reverse(ans);
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends