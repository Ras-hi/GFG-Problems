//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool four(int x){
        while(x>0){
            if(x%10==4) return true;
            x/=10;
        }
        return false;
    }
    int countNumberswith4(int n) {
        // code here
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(four(i)){
                cnt++;
            }
                
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends