#define ll long long

class Solution {
    ll ans = 0;
    
public:
    ll dfs(vector<int> &vis , int node , int seats , vector<int> adj[]) {
        vis[node] = 1;  // mark node as visited
        ll count = 1;   // initialize count of visited nodes
        
        // traverse all unvisited neighbours of the node
        for(auto it : adj[node]) {
            if(!vis[it]) {
                count = count + dfs(vis , it , seats , adj);
            }
        }
        
        // calculate the fuel cost required to visit all nodes reached so far 
        ll x = count /seats;
        
        if(count % seats)
            x++;
        
        if(node != 0)
            ans = ans + x;
        
        // return the count of visited nodes.
        return count;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        
        // adjacency list and visited array.
        vector<int> adj[n + 1] , vis(n + 1 , 0);
        
        // creating the adjacency list.
        for(auto i : roads) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        // dfs function call.
        dfs(vis , 0 , seats , adj);
        
        return ans;   // minimum fuel cost.
    }
};   // TC , SC - O(N)