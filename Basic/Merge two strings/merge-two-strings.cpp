//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge (string S1, string S2)
{
    // your code here
   string str="";
    int n=S1.length();
    int m=S2.length();
    
    if(n==0){
        return S2;
    }
    if(m==0){
        return S1;
    }
    
    int i=0, j=0;
    while(i<n && j<m){
        str=str+S1[i]+S2[j];
        i++;
        j++;
    }
    while(i<n){
        str=str+S1[i];
        i++;
    }
    while(j<m){
        str=str+S2[j];
        j++;
    }
    return str;
}