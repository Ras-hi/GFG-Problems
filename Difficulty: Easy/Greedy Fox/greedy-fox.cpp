//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;
#include<math.h>
int largestSum(int arr[], int N);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;++i)
			cin>>arr[i];
		cout<<largestSum(arr,N)<<endl;
	}
	return 0;
}
// } Driver Code Ends


int largestSum(int arr[], int n)
{
    int result =0;
    for(int i =0;i<n;i++){
        int curr_sum =arr[i];
        while(i+1<n && arr[i+1]>arr[i]){
            curr_sum +=arr[i+1];
            i++;
        }
        if(curr_sum > result){
            result =curr_sum ;
        }
    }
    return result;
}