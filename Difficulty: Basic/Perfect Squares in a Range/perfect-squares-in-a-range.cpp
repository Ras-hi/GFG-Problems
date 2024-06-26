//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int numOfPerfectSquares(int a, int b) {
        // code here
        int frst =sqrt(a);
        int scnd= sqrt(b);
        int ans =scnd-frst ;
        if(frst*frst ==a)
            return ans+1;
        else
            return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.numOfPerfectSquares(a,b) << endl;
    }
    return 0;
}
// } Driver Code Ends