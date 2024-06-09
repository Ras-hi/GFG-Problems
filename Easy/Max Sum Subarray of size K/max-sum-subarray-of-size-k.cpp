//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &a , int n){
        // code here 
        long long sum =0,left=0,maxi=0;
        for(int i=0;i<k;i++){
            sum +=a[i];
        }
        long long windowsum =sum ;
        for(int j =k ;j<n;j++){
            sum =sum -a[left++]+a[j];
            windowsum =max(windowsum , sum);
        }
        return windowsum ;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends