//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans=1;
        int mod=1e9+7;
        long long k=2;
        for(int i=2;i<=n;i++){
            long long t=1;
            for(int j=1;j<=i;j++){
                t=(t*k)%mod;
                k++;
            }
            ans=(ans+t)%mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends