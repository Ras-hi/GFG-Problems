//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        string res;
        if(S == 0 && N!=1) return "-1";
        if(9*N < S) return "-1";
        
        while(N--){
            
            if(S >= 9){
                res.push_back('9');
                S-=9;
            }
            
            else {
                res.push_back(S + '0');
                S = 0;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends