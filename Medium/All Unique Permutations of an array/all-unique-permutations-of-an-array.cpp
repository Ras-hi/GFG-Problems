//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> ans;
        sort(arr.begin(),arr.end());
        ans.insert(arr);
        while(1){
            next_permutation(arr.begin(),arr.end());
            ans.insert(arr);
            bool br = true;
            for(int i=0;i<n-1;i++) if(arr[i+1]>arr[i]) br = false;
            if(br) break;
        }
        vector<vector<int>> ret;
        for(auto i:ans) ret.push_back(i);
        return ret;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends