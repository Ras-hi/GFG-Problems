//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int n=s.size()-1;
        while(n>=0){
            if(s[n]=='0'){
                s[n]='1';
                break;
            }else{
                s[n]='0';
            }
            n--;
        }
        if(n==-1){
            return "1"+s;
        }
        n=0;
        while(s[n]=='0'){
            n++;
        }
        s=s.substr(n);
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends