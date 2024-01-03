//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
           int cnt0=0, cnt1=0, cnt2=0;
        int res=INT_MAX;
        int pos=0;
        int n = S.length();
        for(int i=0;i<n;i++){
            if(S[i]=='0'){
                cnt0++;
            }
            else if(S[i]=='1'){
                cnt1++;
            }
            else{
                cnt2++;
            }
            
            if(cnt1>0 and cnt2>0 and cnt0>0){
                while(cnt0 and cnt1 and cnt2){
                    if(S[pos]=='0'){
                        cnt0--;
                    }
                    else if(S[pos]=='1'){
                        cnt1--;
                    }
                    else{
                        cnt2--;
                    }
                    pos++;
                }
                pos--;
                if(S[pos]=='0'){
                        cnt0++;
                    }
                    else if(S[pos]=='1'){
                        cnt1++;
                    }
                    else{
                        cnt2++;
                    }
                res=min(res,(i-pos+1));
               // cout<<res<<" "<<i<<endl;
                
            }
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends