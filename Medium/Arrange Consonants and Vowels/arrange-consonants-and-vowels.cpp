//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        if(head == NULL || head -> next == NULL) return head;
        Node *t = new Node('*');
        t->next = head;
        Node *s = NULL;
        Node *strt = NULL;
        while(t->next != NULL){
            if(t->next->data == 'a' || t->next->data == 'e' || t->next->data == 'i' || t->next->data == 'o' || t->next->data == 'u'){
                if(s == NULL){
                    s = t->next;
                    strt =t->next;
                }else{
                    s->next = t->next;
                    s = t->next;
                }
                if(t->next == head){
                    head=head->next;
                    t=t->next;
                }else{
                    t->next = t->next->next;
                }
            }
            else t=t->next;
        }
        if(s != NULL){
            s->next = head;
            return strt;
        }else{
            return head;
        }
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends