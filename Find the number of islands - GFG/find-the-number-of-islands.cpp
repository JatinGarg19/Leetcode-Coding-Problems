//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // BFS Function
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
            
            // Traverse in the neighbours and mark them if its a land
            for(int dr = -1; dr <= 1; dr++) {
                for(int dc = -1; dc <= 1; dc++) {
                    int nrow = row + dr;
                    int ncol = col + dc;
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1'
                       && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        
    }
  
  
    // Function to find the number of islands.
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends