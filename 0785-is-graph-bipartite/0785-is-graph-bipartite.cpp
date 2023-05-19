class Solution {
public:
    bool bipartiteBfs(int node, vector<vector<int>>& graph, vector<int> &color)
    {
        color[node] = 0;
        
        queue<int> q;
        
        q.push(node);
        
        while(!q.empty()) {
            int x = q.front(); q.pop();
            
            for(auto nbr: graph[x]) {
                if(color[nbr] == -1) {
                    color[nbr] = 1 - color[x];
                    q.push(nbr);
                }
                else if(color[nbr] == color[x]) {
                    return false;    
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        /*vector<vector<int>> adj(n);
        for(int i=0; i<graph.size(); i++)
        {
            int u = graph[i][0];
            int v = graph[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }*/
        
        vector<int> color(n + 1, -1);
        
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(!bipartiteBfs(i, graph, color))
                    return false;
            }
        }
        
        return true;
    }
};