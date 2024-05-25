//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        string str=S;
        int adjustment =0;
        for(int i=0;i<Q;i++){
            int idx=index[i];
            string src=sources[i];
            string tar=targets[i];
            string f=S.substr(idx,src.size());
            if(f!=src){
                continue;
            }
            str.erase(idx+adjustment,src.size());
            str.insert(idx+adjustment , tar);
            adjustment +=(tar.size()-src.size());
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}
// } Driver Code Ends