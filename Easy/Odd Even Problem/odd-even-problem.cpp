//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int n =s.length();
        map<char,int>mp;
        for(int i=0;i<n ;i++)
            mp[s[i]]++;
        int x=0,y=0;
        for(auto it:mp){
            int a =(it.first -'a')+1;
            if(a%2==0){
                if(it.second%2==0)
                    x++;
            }
            else{
                if(it.second%2)
                    y++;
            }
        }
        if((x+y)%2 ==0) 
            return "EVEN";
        return "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends