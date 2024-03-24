//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void solve(int ind, int n, int one, int zero, vector<string>&ans, string s)
    {
        if(ind==n){
            if(one >= zero){
                ans.push_back(s);
            }
            return;
        }
        if(one < zero){
            return;
        }
        solve(ind+1, n, one+1, zero, ans, s+'1');
        solve(ind+1, n, one, zero+1, ans, s+'0');
    }
 
vector<string> NBitBinary(int n)
{
    vector<string>ans;
    string s="";
    solve(0, n, 0, 0, ans, s);
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    return ans;
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
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends