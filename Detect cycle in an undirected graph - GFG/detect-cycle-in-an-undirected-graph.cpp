//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Bfs function
    bool detect(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        
        // Make a pair of node and its parent and push to queue
        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjNode : adj[node]) {
                // If adjacent node is not visited, mark it visited and push to queue.
                if(!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                // If it is visited and coming from a different node, then cycle is present.
                else if(parent != adjNode) {
                    return true;
                }
            }
        }
        
        // Otherwise return false.
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // Create a visited array to mark nodes as visited
        int vis[V] = {0};
        
        // Using for loop because a graph can have connected components with cycle.
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                // if func returns true, return true else false;
                if(detect(i, adj, vis)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends