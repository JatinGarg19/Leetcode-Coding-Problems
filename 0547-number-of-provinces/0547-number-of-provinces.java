class Solution {
    public int findCircleNum(int[][] isConnected) {
        // Count provinces
        int provinces = 0;
        int n = isConnected.length;
        
        // Converting Adjacency Matrix to adjacency list
        ArrayList<ArrayList<Integer>> adjLs = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            adjLs.add(new ArrayList<>());
        }
        
        for(int i = 0; i < isConnected.length; i++) {
            for(int j = 0; j < isConnected[0].length; j++) {
                // If there is an edge and it is not a self edge.
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs.get(i).add(j);
                }
            }
        }
        
        int vis[] = new int[n];
        for(int i = 0; i < n; i++) {
            // If the particular node is not visited, inc the province and apply dfs on neigbor
            if(vis[i] == 0) {
                provinces++;
                dfs(i ,vis, adjLs);
            }
        }
        
        // return answer
        return provinces;
    }
    
    public void dfs(int node, int vis[], ArrayList<ArrayList<Integer>> adjLs) {
        // mark the node as visited.
        vis[node] = 1;
        
        // get the neighbouring nodes and apply dfs
        for(Integer it : adjLs.get(node)) {
            if(vis[it] == 0) {
                dfs(it, vis, adjLs);
            }
        }
    }
}