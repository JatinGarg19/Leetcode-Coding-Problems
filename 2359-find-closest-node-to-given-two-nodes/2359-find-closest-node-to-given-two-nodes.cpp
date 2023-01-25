class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> dist_node1(n, -1);
        vector<int> dist_node2(n, -1);
        
        vector<bool> vis(n, false);
        
        dfs(node1, dist_node1, vis, edges, 0);
        vis.assign(n, false);
        dfs(node2, dist_node2, vis, edges, 0);
        
        int ans = n;
        int result = -1;
        for(int i = 0; i < n; i++)
        {
            if(dist_node1[i] != -1 && dist_node2[i] != -1)
            {
                if(max(dist_node1[i], dist_node2[i]) < ans)
                {
                    ans = max(dist_node1[i], dist_node2[i]);
                    result = i;
                }
            }
        }
        
        return result;
    }
    
    void dfs(int node, vector<int> &dist_node1, vector<bool> &vis,
             vector<int> &edges, int distance)
    {
        if(node != -1 && !vis[node])
        {
            vis[node] = true;
            dist_node1[node] = distance;
            dfs(edges[node], dist_node1, vis, edges, distance + 1);
        }
    }
};