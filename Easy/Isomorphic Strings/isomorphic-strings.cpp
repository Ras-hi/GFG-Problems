//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.size()!=str2.size())return 0;
        map<char,char>m;
        int n=str1.size();
        for(int i=0;i<n;i++){
            if(m[str1[i]]!='\0'){
                if(m[str1[i]]!=str2[i])return 0;
            }
            else{
                m[str1[i]]=str2[i];
            }
        }
        set<char>s1,s2;
        for(int i=0;i<n;i++){
            s1.insert(str1[i]);
        }
        for(int i=0;i<n;i++){
            s2.insert(str2[i]);
        }
        return s1.size()==s2.size();
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends