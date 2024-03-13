//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         vector<int>ans;

         int i=0,j=0;

         map<int,vector<int>>v;

    for(i=0;i<mat.size();i++){

        for(j=0;j<mat[0].size();j++){

            v[i+j].push_back(mat[i][j]);

        }

    }

 bool b=false;

    for(auto it : v){

        vector<int>m=it.second;

    if(b){

        b=false;

    }

    else{

   reverse(m.begin(),m.end());

        b=true;

    }

    for(auto i:m){

        ans.push_back(i);

    }

    }

    return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends