//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        // code here
                int wind=0,pind=0;
        while(wind<wild.length() or pind<pattern.length()){
            if(wild[wind]==pattern[pind] or wild[wind]=='?' or wild[wind]=='*'){
                if(wild[wind]=='*'){
                        while(wind<wild.length() and (wild[wind]=='?' or wild[wind]=='*')) wind++;
                        if(wind==wild.length()) return true;
                        pind++;
                        while(pattern[pind]!=wild[wind] and pind<pattern.length()) pind++;
                        if(pind==pattern.length()) return false;
                }
                wind++;
                pind++;
            }
            else return false;
        }
        if(pind<pattern.length() or wind<wild.length()) return false;
        return true;

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends