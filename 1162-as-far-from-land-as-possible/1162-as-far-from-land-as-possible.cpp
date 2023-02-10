class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int,int>> q;
        
        vector<vector<int>> dist(n , vector<int>(n , -1));
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r , c});
                }
            }
        }
        
        int result = 0;
        
        int dR[] = {0 , 0 , 1 , -1};
        int dC[] = {1 , -1 , 0 , 0};
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            if(grid[row][col] == 0)
                result = max(result , dist[row][col]);
            
            for(int i = 0; i < 4; i++) {
                int newR = row + dR[i];
                int newC = col + dC[i];
                
                if(newR >= 0 and newR < n and newC >= 0 and newC < n and dist[newR][newC] == -1) {
                    dist[newR][newC] = dist[row][col] + 1;
                    q.push({newR , newC});
                    
                }
            }
        }
        
        // Checking the return statement.
        return (result == 0) ? -1 : result;
    }
};