//{ Driver Code Starts
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
    public:
    //Function to add two numbers represented by linked list.
     Node* rev(Node *head){
        Node *cur=head;
        Node *prev=NULL;
        Node *after=NULL;
        
        while(cur!=NULL){
            after=cur->next;
            cur->next=prev;
            prev=cur;
            cur=after;
        }
        
        return prev;
    }
    Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        if(num1==NULL)
        return num2;
        
        if(num2==NULL)
        return num1;
        
        Node *temp=new Node(-1);
        Node *cur=temp;
        
        Node *l1=rev(num1);
        Node *l2=rev(num2);
        
        int carry=0;
        
        while((l1!=NULL || l2!=NULL) || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->data;
                l2=l2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            
            Node *node=new Node(sum%10);
            cur->next=node;
            cur=cur->next;
        }
        
        temp=rev(temp->next);
        while(temp->data==0 && temp->next!=NULL)
        temp=temp->next;
        
        return temp;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends