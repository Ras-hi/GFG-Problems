//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
     int countSetBits(int n)
    {
        // Your logic here
        if(n<=1)
        {
            return n;
        }
        int x=log2(n);
        return pow(2,x-1)*x+n-pow(2,x)+1+countSetBits(n-pow(2,x));
    }


    
    
    // LOOKUP TABLE METHOD 
    
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
//     std::vector<int> precomputeSetBits(int limit) {
//     std::vector<int> setBits(limit + 1, 0);
//     for (int i = 1; i <= limit; i++) {
//         setBits[i] = setBits[i >> 1] + (i & 1);
//     }
//     return setBits;
// }

// // Function to calculate the sum of set bits for numbers from 1 to n
// int countSetBits(int n) {
//     std::vector<int> setBits = precomputeSetBits(n);
//     int sum = 0;
//     for (int i = 1; i <= n; i++) {
//         sum += setBits[i];
//     }
//     return sum;
// }
        // Your logic here
        
        // 01- BRIAN KERNIGHAN'S METHOD -->> TLE 
        
        // int sum=0;
        // for(int i=1;i<=n;i++){
        //     int cnt=0;
        //     int num=i;
        //     while(num>0){
        //         num=num&(num-1);
        //         cnt++;
        //     }
        //     sum+=cnt;
        // }
        // return sum;
    
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends