//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


void printCorner(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        printCorner(root);
        cout<<endl;
    }
    return 0;
}









// } Driver Code Ends


/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
void printCorner(Node *root)
{

// Your code goes here
 queue<Node *> q;

    // pushing root node and star node
    q.push(root);
    q.push(NULL);

    // if isFirst = true then left most node of that level
    // will be printed
    bool isFirst = false;

    // if isOne = true then that level has only one node
    bool isOne = false;

    // last will store right most node of that level
    int last;

    // Do level order traversal of Binary Tree
    while (!q.empty())
    {
        // dequeue the front node from the queue
        Node *temp = q.front();
        q.pop();

        // if isFirst is true, then temp is leftmost node
        if (isFirst)
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            // make isFirst as false and one = 1
            isFirst = false;
            isOne = true;
        }

            // Else if temp is a separator between two levels
        else if (temp == NULL)
        {
            // Insert new separator if there are items in queue
            if (q.size() >= 1)
                q.push(NULL);

            // making isFirst as true because next node will be
            // leftmost node of that level
            isFirst = true;

            // printing last node, only if that level
            // doesn't contain single node otherwise
            // that single node will be printed twice
            if (!isOne)
                cout << last << " ";
        }
        else
        {
            // Store current key as last
            last = temp->data;

            // Here we are making isOne = false to signify
            // that level has more than one node
            isOne = false;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}