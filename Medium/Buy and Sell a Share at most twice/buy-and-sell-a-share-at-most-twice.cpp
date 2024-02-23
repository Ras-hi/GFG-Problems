//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
             int n = price.size(), ind, buy, cap, take, notTake;
            vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
            for(ind = n-1; ind >= 0; ind--)
            {
                for(buy = 0; buy <= 1; buy++)
                {
                    for(cap = 1; cap <= 2; cap ++)
                    {
                        take = notTake = 0;
                        if(buy == 1)
                        {
                            take = -price[ind] + dp[ind + 1][0][cap];
                            notTake = dp[ind + 1][1][cap];
                        }
                        else
                        {
                            take = price[ind] +  dp[ind + 1][1][cap - 1];
                            notTake =  dp[ind + 1][0][cap];
                        }
                        dp[ind][buy][cap] = max(take, notTake);
                    }
                }
            }
            return dp[0][1][2];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends