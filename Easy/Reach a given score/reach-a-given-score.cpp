//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int count(long long int amount)
    {
    	// Your code here
    	// Initialize a vector to store the number of ways to make change for each amount
        std::vector<int> ways(amount + 1, 0);
        ways[0] = 1;

        // Update the vector based on the coins available
        std::vector<int> coins = {3, 5, 10};
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                ways[i] += ways[i - coin];
            }
        }

        // Return the number of ways to make change for the given amount
        return ways[amount];
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends