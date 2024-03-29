//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	    // Iterate over each vertex in the graph
        for(int i = 0; i < v; i++) {
            // Check if the number of edges incident to the current vertex is odd
            if(adj[i].size() % 2 != 0) {
                // If the number of edges incident to the vertex is odd, return false
                // as an Eulerian circuit cannot exist in such a graph
                return false;
            }
        }
        // If the function has not returned false during the iteration, it means
        // all vertices have an even number of incident edges, so return true
        // indicating that an Eulerian circuit exists in the graph
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends