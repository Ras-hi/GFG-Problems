//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int arr[26]={0};
   for(int i=0;i<s.length();i++)
   arr[s[i]-'a']++;
   unordered_map<int,int>m;
   for(int i=0;i<26;i++)
   {
       if(arr[i]!=0)
       m[arr[i]]++;
   }
   if(m.size()>2)
   return false;
   int h=0;
   int k=0;
   for(auto i:m)
   {
       if(h==0){
       h=i.first;
       k=i.second;
       }
       else
       {
           if(abs(h-i.first)==1 && (k==1 || i.second==1))return true;
           return false;
       }
       
   }
   return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends