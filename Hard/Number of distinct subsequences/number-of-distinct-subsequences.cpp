//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
    int mod = 1e9+7;
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.size();
        int dp[n+1] = {0};
        
        dp[0] = 1;
        map<int, int>mp;
        
        for(int i=1; i<=n; i++)
        {
            dp[i] = (dp[i-1]*2)%mod;
            
            if(mp[s[i-1]]) dp[i] = (dp[i]-dp[mp[s[i-1]]-1]+mod)%mod;
            mp[s[i-1]] = i;
        }
        
        return dp[n];
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends