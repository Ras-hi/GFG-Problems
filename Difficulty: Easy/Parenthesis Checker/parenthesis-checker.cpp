//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(char ch:x){
            if(ch =='(' || ch=='[' || ch =='{'){
                st.push(ch);
            }
            else if(ch ==')' || ch ==']' || ch =='}'){
                if(st.empty()){
                    return false;
                }
                char top =st.top();
                st.pop();
                if((ch ==')' && top!='(' )|| (ch ==']' && top!='[' )|| (ch =='}' && top!='{' )){
                    return false;
                }
            }
        }
        return st.empty() ;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends