//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int n =arr.size();
        int max_sum =arr[0];
        int curr_sum=0;
        for(int i =0;i<n ;i++){
            curr_sum +=arr[i];
            max_sum =max(max_sum ,curr_sum);
            if(curr_sum<0){
                curr_sum =0;
            }
        }
        return max_sum ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl << "~" << endl;
    }
}
// } Driver Code Ends