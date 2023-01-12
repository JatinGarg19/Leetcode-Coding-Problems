class Solution {
    vector<int> array;
    vector<int> visited;
public:
    vector<int> dfs(int node, vector<vector<int>> &adj, string &labels) {
        // Mark the node as visited.
        visited[node] = 1;   
        
        // Count array to mark the count of char in the subtrees
        vector<int> count(26); 
        
        // traversing the neighbouring nodes of parent node
        for(auto x : adj[node]) {   
            // Call dfs only for the nodes that are not visited
            if(!visited[x]) {      
                vector<int> adjCount = dfs(x, adj, labels);
                // adding the labels of all the subtree labels.
                for(int i = 0; i < 26; i++) {
                    count[i] += adjCount[i];
                }
            }
        }
        
        char ch = labels[node];
        // adding the label to the count vector
        count[ch - 'a']++;
        // Finally adding the count value to the ans vector.
        array[node] = count[ch - 'a'];
        
        return count;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        array.resize(n);  // Output Array
        visited.resize(n); // Visited array to mark that the prticular node is alrd visited
        
        // Create an adjacency list/matrix.
        vector<vector<int>> adj(n);
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);  // Bcz it is undirected graph
        }
        
        dfs(0, adj, labels);  // dfs function
        return array;     // answer output
    }
};