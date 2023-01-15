class Solution {
    vector<map<int,int>> mp;
    vector<vector<int>> adj;
    // To mark nodes as visited or not visited.
    vector<int> flag;
public:
    
    void dfs(int &count, int u, vector<int> &vals) {
        // Mark the node as visited.
        flag[u] = 1;
        
        for(auto &v : adj[u]) {
            if(flag[v] == 1) continue;
            
            int cnt = 0;
            dfs(cnt, v, vals);
            count += cnt;
            
            auto it = mp[v].lower_bound(vals[u]);
            mp[v].erase(mp[v].begin(), it);
            
            if(mp[u].size() < mp[v].size()) {
                swap(mp[v], mp[u]);
            }
            
            for(auto &it : mp[v]) {
                count += mp[u][it.first] * it.second;
                mp[u][it.first] += it.second;
            }
        }
        
        count += mp[u][vals[u]];
        ++mp[u][vals[u]];
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // Number of nodes
        int n = vals.size();
        
        mp.resize(n);
        
        // Adjacency Matrix
        adj.resize(n);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int ans = 0;
        
        flag.resize(n, 0);
        
        dfs(ans, 0, vals);
        
        // Final ans will be returned value + total nodes itself
        return ans + n;
    }
};