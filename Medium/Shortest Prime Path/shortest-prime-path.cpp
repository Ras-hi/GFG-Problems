//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
// static variables
static int primes[10000];
static unordered_map<string, vector<string>> mp;

// self invoking function
const bool f = [] {
    for(int i=0; i<10000; i++) {
        primes[i] = 1;
    }
    
    for(int i=2; i*i<10000; i++) {
        if(primes[i])
        for(int j=i*i; j<10000; j+=i) {
            primes[j] = 0;
        }
    }
    vector<string> v;
    for(int i=1000; i<=9999; i++) {
          if(primes[i]) {
              v.push_back(to_string(i));
            //   cout << i << " ";
          }
      }

    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            int flg = 0;
            for(int x=0;x<4;x++) flg+=(v[i][x]!=v[j][x]);
            if(flg == 1) {
                mp[v[i]].push_back(v[j]);
                mp[v[j]].push_back(v[i]);
            }
        }
    }
    return true;
}();
// ... IMP

class Solution{
public:
    int solve(int Num1,int Num2)
    {   

      //SIMPLE BFS
      queue<pair<string, int>> q;
      q.push({to_string(Num1), 0});
      string dest = to_string(Num2);
      unordered_set<string> vis;

      while(!q.empty()) {
          string str = q.front().first;
          int c = q.front().second;
          if(str == dest) return c;
          q.pop();
          vis.insert(str);
          
          for(auto s: mp[str]) {
                if(!vis.count(s)) q.push({s, c+1});
          }
      }
      return 0;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends