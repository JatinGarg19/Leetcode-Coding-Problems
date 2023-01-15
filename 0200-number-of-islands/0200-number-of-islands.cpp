class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Mark the value as visited
        vis[row][col] = 1;
        // Pair because we have to store both row number and col number
        queue<pair<int,int>> q;
        q.push({row, col});
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            vector<int> delta = {0,1,0,-1,0};
            
            // Traverse in the neighbours and mark them if its a land
            for(int k = 0; k < 4; k++) {
                int nrow = row + delta[k];
                int ncol = col + delta[k+1];
                    
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1'
                   && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Count to count the number of islands
        int cnt = 0;
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        
        return cnt;
    }
};