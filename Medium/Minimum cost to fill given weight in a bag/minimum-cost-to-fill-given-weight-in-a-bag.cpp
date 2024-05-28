//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        // Create an array to store the minimum cost for each weight from 0 to w
    vector<int> dp(w + 1, INT_MAX);
    
    // Base case: minimum cost to get 0 weight is 0
    dp[0] = 0;

    // Loop through all weights from 1 to w
    for (int i = 1; i <= w; i++) {
        // Loop through all items to find the minimum cost to get i weight
        for (int j = 1; j <= n; j++) {
            if (j <= i && cost[j - 1] != -1) { // Ensure j is within bounds and cost is valid
                dp[i] = min(dp[i], dp[i - j] + cost[j - 1]);
            }
        }
    }

    // If dp[w] is still INT_MAX, it means it's not possible to get exactly w weight
    return dp[w] == INT_MAX ? -1 : dp[w];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends