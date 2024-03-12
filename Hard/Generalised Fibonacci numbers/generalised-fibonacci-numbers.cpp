//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, long long m) {
            int size = A.size();
            // Initialize the result matrix with zeros
            vector<vector<long long>> result(size, vector<long long>(size, 0));
        
            // Perform matrix multiplication
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    for (int k = 0; k < size; ++k) {
                        // Multiply corresponding elements and accumulate the result
                        result[i][j] += A[i][k] * B[k][j];
                        // Apply modulo operation to avoid overflow
                        result[i][j] %= m;
                    }
                }
            }
        
            return result;
        }

long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        if (n <= 2)
                return 1 % m;
        
            // Initialize matrices for matrix exponentiation
            vector<vector<long long>> mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
            vector<vector<long long>> res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        
            // Perform matrix exponentiation to calculate g(n) modulo m
            n -= 2; // g(n) for n > 2 is equivalent to g(n-2)
            while (n > 0) {
                if (n & 1) {
                    // If n is odd, multiply the result matrix by mat
                    res = multiply(res, mat, m);
                }
                // Square the matrix mat for the next iteration
                mat = multiply(mat, mat, m);
                n >>= 1; // Right shift n to divide by 2
            }
        
            // Calculate the final result g(n) modulo m
            return (res[0][0] + res[0][1] + c * res[0][2]) % m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends