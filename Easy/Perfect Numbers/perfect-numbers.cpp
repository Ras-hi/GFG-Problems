//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        long long sum=0;
        for(long long i=1;i<=sqrt(N);i++){
            if(N%i==0 && i!=N){
                sum+=i;
                
            }
            
            if((N/i)!=i){
                if(N%(N/i)==0 && (N/i!=N)){
                    sum+=(N/i);
                
                }
                
            }
        }
        
        if(sum==N){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends