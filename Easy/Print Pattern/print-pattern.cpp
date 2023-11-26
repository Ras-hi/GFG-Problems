//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
        // code here
            if(N==0){
            return {0};
        }
        vector<int> v;
        int ans=N;
      while(ans > 0){
         v.push_back(ans);
         ans=ans-5;
      }
      while(ans <= N){
         v.push_back(ans);
         ans=ans+5;
      }
    
       return v;

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
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends