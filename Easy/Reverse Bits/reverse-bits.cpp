//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long res=0;
        for(int i=31;i>=0;i--){
            long long digit=x&1;// to get the LSB
            x=x>>1;// to move the LSB from left to right
            digit =digit<<i;// excchange the LSB to MSB 
            res= res|digit ;//updating all the digits 
            
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