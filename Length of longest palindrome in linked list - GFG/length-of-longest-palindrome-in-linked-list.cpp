// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
int countCommon(Node *previous,Node* next){
    int ansHalf = 0;
    for(Node *curr1 = previous, *curr2 = next;
    curr1 && curr2 && curr1->data == curr2->data;curr1 = curr1->next,curr2 = curr2->next){
        ansHalf++;
    }
    return ansHalf;
}
Node* reverseList(Node* head,int &ans){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr){
        Node *next = curr->next;
        curr->next = prev;
        ans = max(ans,1+countCommon(prev,next)*2);
        ans = max(ans,countCommon(curr,next)*2);
        prev = curr;
        curr = next;
    }
}
int maxPalindrome(Node *head)
{
    //Your code here
    int ans = 0;
    head = reverseList(head,ans);
    head = reverseList(head,ans);
    return ans;
}