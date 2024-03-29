//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        int L[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    L[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    L[i][j]=1+L[i-1][j-1];
                }
                else{
                    L[i][j]=max(L[i-1][j],L[i][j-1]);
                }
            }
        }
        return L[n][m];
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends