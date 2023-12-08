//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int dp[1000001]={0};
set<int> primes;
bool flag = 0;
void initialize() {
    if(flag) return; //make sure to initialze only once ;)
    for(int i=2;i<=1000000;i++){
        if(!dp[i]){
            primes.insert(i);
            int x = 1;
            while(x*i<=1000000){dp[x*i]=1; x++;}
        }
    }
    flag = 1; //initialized
}
class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        initialize();
        int sum = 0; for(int i=0;i<N;i++) sum += arr[i];
        auto itr = primes.lower_bound(sum);
        if(itr == primes.end()) return -1;
        return *itr - sum;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends