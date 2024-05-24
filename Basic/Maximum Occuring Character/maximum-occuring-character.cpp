//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
         int freq[26] = {0};
        int maxfreq = -1;
        char maxfreqchar;
        
        for(int i=0; i<str.size(); i++){
            freq[str[i] - 'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(maxfreq<freq[i]){
                maxfreq = freq[i];
                maxfreqchar = (char)(i+'a');
            }
        }
        return maxfreqchar;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends