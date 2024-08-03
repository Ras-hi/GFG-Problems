//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int gcd(int i ,int j){
        if(i==j) return i ;
        if(i>j){
            return gcd(i-j,j);
        }
        return gcd(i,j-i);
    }
    int isPossible(int x, int y, int a, int b) {
        // code here
        x=abs(x),y=abs(y),a=abs(a),b=abs(b);
        return gcd(x,y)==gcd(a,b);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x,y,a,b;
        
        cin>>x>>y>>a>>b;

        Solution ob;
        cout << ob.isPossible(x,y,a,b) << endl;
    }
    return 0;
}
// } Driver Code Ends