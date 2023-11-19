//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    private:
    void insertTail(Node* &head, Node* &tail, int val) {
        Node *temp = new Node(val);
        
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        
        while(head1 != NULL and head2 != NULL) {
           // value of head1 and head2 is same then put it in answer linkList and move to the next node
            if(head1->data == head2->data) {
                insertTail(ansHead, ansTail, head1->data);
                head1 = head1->next;
                head2 = head2->next;
                continue;
            }
            
            // if value of head1 and head2 are different then we check which one is smaller 
            // and update move to the next accordingly 
            if(head1->data < head2->data)
                head1 = head1->next;
            else
                head2 = head2->next;
        }
        
        return ansHead;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends