//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        
        vector<int> ans;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end());
        sort(b.begin(),b.end());
        map<int,int>mp;
        int i=0,j=0;
        while(i<n&&j<n){
            if(b[j]<=v[i].first){
                j++;
            }
            else{
                mp[v[i].second]=j;
                i++;
            }
        }
        while(i<n){
            mp[v[i].second]=j;
            i++;
        }
        for(int i=0;i<q;i++){
             ans.push_back(mp[query[i]]);
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
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends