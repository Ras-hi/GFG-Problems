//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans=0;
        bool flag=0;
        for(auto i:s){
            if(i=='-' ){
                if(flag==1 || ans>0) return -1;
                else 
                flag=1;
            }
            
            else if(i>=48 && i<=57 ) ans = (ans*10) + i - 48 ;
            else return -1;
            
            // cout<<ans<<endl;
        }
        
        if(flag==1) return ans*-1;
        return ans;

    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends