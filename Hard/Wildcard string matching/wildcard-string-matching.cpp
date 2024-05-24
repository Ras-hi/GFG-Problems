//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size();
        int m = pattern.size();
        
        int i = 0, j = 0;
        int checkpointWild = -1, checkpointPattern = -1;
    
        while (j < m) {
            if (i < n && (wild[i] == pattern[j] || wild[i] == '?')) {
                i++;
                j++;
            } else if (i < n && wild[i] == '*') {
                checkpointWild = i;
                checkpointPattern = j;
                i++;
            } else if (checkpointWild != -1) {
                // Backtrack to the last '*' checkpoint
                i = checkpointWild + 1;
                j = checkpointPattern + 1;
                checkpointPattern++;
            } else {
                return false;
            }
        }
    
        while (i < n && wild[i] == '*') {
            i++;
        }
    
        return i == n && j == m;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends