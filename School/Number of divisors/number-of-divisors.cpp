//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		int count_divisors(int n)
		{
		    //Code here.
		  //  vector<int>a;
		  //  int cnt=0;
		  //  for(int i=1;i<=n;i++){
		  //      if(n%i==0){
		  //          a.push_back(i);
		  //      }
		  //  }
		  //  for(int i=0;i<a.size();i++){
		  //      if(a[i]%3==0){
		  //          cnt++;
		  //      }
		  //  }
		  //  return cnt;
		   int c=0;
            //Code here.
            for(int a=1; a*a<=n; a++){
                if(n%a==0){
                    if(a==n/a){
                        if(a%3==0)
                            c++;
                    }else{
                        if(a%3==0){
                            c++;
                        }
                        if((n/a)%3==0)
                            c++;
                    }
                }
            }
            return c;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	int ans = ob.count_divisors(n);
    	cout << ans << "\n";
    }
	return 0;
}
// } Driver Code Ends