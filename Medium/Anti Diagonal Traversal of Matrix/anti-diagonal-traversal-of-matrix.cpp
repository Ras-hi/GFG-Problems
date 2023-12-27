//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
         int n = matrix.size();
        vector<int> ans; 
        vector<vector<int>> vis(n+1, vector<int>(n+1, -1));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==-1){
                    ans.push_back(matrix[i][j]);
                    vis[i][j] = 1;
                    int x = i, y = j;

                    while(x+1>=0 && y-1>=0 && x+1<n && y-1<n && vis[x+1][y-1]==-1){
                        x++;
                        y--;
                        ans.push_back(matrix[x][y]);
                        vis[x][y] = 1;
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends