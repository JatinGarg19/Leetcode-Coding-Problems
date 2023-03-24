class Solution {
public:
    void dfs(vector<int> adj[], vector<bool>& visited, int node) {
        visited[node] = true;
        
        for(int i : adj[node]) {
            if(!visited[i])
                dfs(adj, visited, i);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        
        // if length of array is less than n - 1 computers.
        if(len < n - 1) return -1;
        
        // Adjacency Matrix.
        vector<int> adj[n];
        
        for(auto v : connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> visited(n, false);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(adj, visited, i);
                ans++;
            }
        }
        
        return ans - 1;   // TC - O(Vertices + Edges) , Sc - O(V) for dfs + O(V + E) for adj.
    }
};