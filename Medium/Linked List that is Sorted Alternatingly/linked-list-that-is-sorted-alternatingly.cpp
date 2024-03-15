//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    Node *reverse(Node *head){
        if(!head || !head->next) return head;
        
        Node *prev = NULL, *curr = head, *nxt = NULL;
        
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
        Node *merge(Node *head1, Node *head2){
        Node *ptr1 = head1;
        Node *ptr2 = head2;
        Node *prev = ptr1;


        while(ptr1 && ptr2){
            if(ptr1->data<=ptr2->data){
                prev = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                prev->next = ptr2;
                prev = ptr2;
                Node *temp = ptr2->next;
                ptr2->next = ptr1;
                ptr2 = temp;
            }
        }


        if(ptr1) prev->next = ptr1;
        if(ptr2) prev->next = ptr2;


        return head1;
    }


    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
         if(!(*head)->next) return ;
         
         Node *head1 = *head;
         Node *head2 = (*head)->next;
         Node *ptr1 = head1;
         Node *ptr2 = head2;
         

//step 1: split the list into two lists
         while(ptr2 && ptr2->next){
            ptr1->next = ptr2->next;
            ptr1 = ptr1->next;
            ptr2->next = ptr1->next;
            ptr2 = ptr2->next;
         }
         ptr1->next = NULL;
         

//step 2: reverse the descending list
         head2 = reverse(head2);
         

//step 3: merge the two sorted lists
         if(head1->data <= head2->data)
         *head = merge(head1,head2);
         else
         *head = merge(head2,head1);
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends