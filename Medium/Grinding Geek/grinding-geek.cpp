//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int check(vector<int> &cost,int i,int total,vector<vector<int>>&dp,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i][total]!=-1){
            return dp[i][total];
        }
        if(total>=cost[i]){
            int price = cost[i] - floor(0.9*cost[i]);
            return dp[i][total]= max( 1 + check(cost ,i+1 , total-price ,dp,n), check(cost ,i+1 , total , dp,n));
        }
        return dp[i][total]=check(cost,i+1,total,dp,n);
    } 
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));
        return check(cost,0,total,dp,n);
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends