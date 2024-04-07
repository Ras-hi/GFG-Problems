//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int arr[],int i,int j,long long sum,vector<vector<long long>>&dp){
        if(j-i==1){
            return max(arr[i],arr[j]);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long t1 = solve(arr,i+1,j,sum-arr[i],dp);
        long long t2 = solve(arr,i,j-1,sum-arr[j],dp);
        if(t1 < t2){
            return dp[i][j] = sum-t1;
        }
        else{
            return dp[i][j] = sum-t2;
        }
    }
    long long maximumAmount(int n, int arr[]){
        vector<vector<long long>>dp(n,vector<long long>(n,-1));
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        return solve(arr,0,n-1,sum,dp);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends