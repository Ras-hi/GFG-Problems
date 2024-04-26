//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        unordered_map<char, pair<int, int>> mpp, go;
        // mpp map is for to change the direction when 1 is encountered
        mpp['>'] = {1,0};
        mpp['<'] = {-1, 0};
        mpp['^'] = {0, 1};
        mpp['*'] = {0,-1}; // * indicates dowm direction
        
        // go map is for continue in the going direction
        go['>'] = {0, 1};
        go['<'] = {0, -1};
        go['^'] = {-1, 0};
        go['*'] = {1, 0};
        
        char ch = '>';
        int i=0, j = 0;
        
        while(i>=0 && j>=0 && i < n && j < m )
        {
            int iOld = i,  jOld = j;
            if(matrix[i][j] == 0)
            {
                pair<int, int> p = go[ch];
                i += p.first;
                j += p.second;
            }
            else
            {
                matrix[i][j] = 0;
                pair<int, int> p = mpp[ch];
                i += p.first;
                j += p.second;
                if(ch == '>') ch = '*';
                else if(ch == '<') ch = '^';
                else if(ch == '^') ch = '>';
                else ch = '<';
            }
            if(i<0 || j<0 || i>=n || j>=m)
            return {iOld, jOld};
        }
        return {};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends