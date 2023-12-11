//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &a , int n){
        // code here 
        long int cur_sum = 0;
        long int max_sum = INT_MIN;
        int j = 0, i = 0;
        while(i<n){
            if(i<k){
                cur_sum += a[i];
            }
            else{
                max_sum = max(max_sum,cur_sum);
                cur_sum -= a[j];
                cur_sum += a[i];
                j++;
            }
            i++;
        }
        max_sum = max(cur_sum, max_sum);
        return max_sum;

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