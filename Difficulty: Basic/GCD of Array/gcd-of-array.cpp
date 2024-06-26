//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int gcd(int a ,int b){
	    while(a>0 &b>0){
	        if(a>b)
	            a=a%b;
	        else
	            b=b%a;
	   
	    }
	    if(a>0) return a ;
	    return b ;
	}
    int gcd(int N, int arr[])
    {
    	// Your code goes here
    	int res=0;
    	for(int i=0;i<N;i++){
    	    res=gcd(res,arr[i]);
    	}
    	return res;
    }
};


//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0; i < N; i++)
        	cin >> arr[i];
        Solution ob;
       	cout <<  ob.gcd(N, arr) << "\n";
   
    }
    return 0;
}
// } Driver Code Ends