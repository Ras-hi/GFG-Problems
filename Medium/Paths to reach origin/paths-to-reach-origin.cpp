//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int mod=1e9+7;
class Solution
{
    public:
    int ways(int x, int y)
    {
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        dp[0][0]=1;
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0 and j==0)
                continue;
                
                int temp=0;
                if(i-1>=0)
                temp=(temp+dp[i-1][j])%mod;
                
                if(j-1>=0)
                temp=(temp+dp[i][j-1])%mod;
                
                dp[i][j]=temp;
            }
        }
        return dp[x][y];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends