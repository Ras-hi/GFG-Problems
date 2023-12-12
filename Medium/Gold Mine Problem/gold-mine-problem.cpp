//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = M[i][m - 1];
        }
        
        for (int j = m - 2; j >= 0; j--) {
            vector<int> curr(n);
            for (int i = 0; i < n; i++) {
                curr[i] = dp[i];
                if (i - 1 >= 0) curr[i] = max(curr[i], dp[i - 1]);
                if (i + 1 < n) curr[i] = max(curr[i], dp[i + 1]);
                curr[i] += M[i][j];
            }
            dp = curr;
        }
        
        return *max_element(dp.begin(), dp.end());

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends