class Solution {
public:
    pair<int,int> coordinates(int x, int n){
        int row = n - (x - 1) / n - 1;
        int col = (x - 1) % n;
        
        if(row % 2 == n % 2)
            return {row, n - col - 1};
        
        return {row, col};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps = 0;
        int n = board.size();
        
        queue<int> q;
        q.push(1);
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[n - 1][0] = true;
        
        while(q.size() != 0) {
            int z = q.size();
            
            for(int i = 0; i < z; i++){
                int x = q.front();
                
                if(x == n * n) 
                    return steps;
                
                q.pop();
                
                for(int j = 1; j <= 6; j++){
                    if(j + x > n * n) 
                        break;
                    
                    pair<int, int> p = coordinates(x + j, n);
                    
                    if(vis[p.first][p.second]) 
                        continue;
                    
                    vis[p.first][p.second] = true;
                    
                    if(board[p.first][p.second] != -1)
                        q.push(board[p.first][p.second]);
                    
                    else
                        q.push(j + x);
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};