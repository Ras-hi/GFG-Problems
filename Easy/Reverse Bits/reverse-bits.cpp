//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long res = 0 ; 
        
        for(int i = 31; i>=0 ; i--){
            
            long long digit = x & 1; 
            x = x>>1; 
            digit = digit << i; 
            
            res = res | digit; 
        }
        
        return res; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends