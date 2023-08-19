//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    
	/* get the index of first occurrence of x */
	    int *low = lower_bound(arr, arr + n, x);

	// If element is not present, return 0
	    if (low == (arr + n) || *low != x)
	        return 0;

	/* Else get the index of last occurrence of x.
		Note that we are only looking in the
		subarray after first occurrence */
	    int *high = upper_bound(low, arr + n, x);

	/* return count */
	    return high - low;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends