//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	static bool comparator(const string &a,const string &b){
	    return (a+b)>(b+a);
	}
	string printLargest(int n, vector<string> &arr) {
	    // code here
	    //no ka first digit ka comparison krenge then if agr do no ka same hai first digit to second digit ka theen sbko string main convert krke append krdenge
	    sort(arr.begin(),arr.end(),comparator);
	    string result;
	    for(int i=0;i<n;i++){
	        result+=arr[i];
	    }
	    //removing leading zeroes if any 
	    while(result[0]=='0' && result.length()>1){
	        result.erase(0,1);
	    }
	    return result;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends