//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int st=0,en=n-1;
        int mid;
        
        while(st<=en)
        {
            mid=(st+en)/2;
            
            if(arr[mid]==x)
                break;
            else if(arr[mid]<x)
                st=mid+1;
            else 
                en=mid-1;
        }
        
        if(arr[mid]!=x)
            return {-1,-1};
            
        st=mid;
        en=mid;
        while(st>=0 && arr[st]==x)
            st--;
            
            
        while(en<n && arr[en]==x)
            en++;
            
        return {st+1,en-1};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends