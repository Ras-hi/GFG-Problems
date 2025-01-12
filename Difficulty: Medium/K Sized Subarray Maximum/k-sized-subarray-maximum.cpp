//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int>ans;// array to store the ans
        deque<int>dq;// deque to store the indices of the elements in the current winfow 
        for(int i =0;i<arr.size();i++){
            //remove elements that are out of the sliding window 
            while(!dq.empty() && dq.front()< i-k+1){
                dq.pop_front();
            }
            //remove elements that are smaller than the max element
            while(!dq.empty() && arr[dq.back()]<arr[i]){
                dq.pop_back();
            }
            // add current element to the back of the dequeu
            dq.push_back(i);
            //append the maximum element in the ans
            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends