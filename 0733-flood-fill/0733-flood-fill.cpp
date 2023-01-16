class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>> &ans, int delRow[], int                      delCol[], int newColor, int iniColor) {
        // mark the value as newColor
        ans[row][col] = newColor;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int k = 0; k < 4; k++) {
            int nRow = row + delRow[k];
            int nCol = col + delCol[k];
            
            // If point is within the limit and has initial color and not yet made newcolor, apply dfs
            if(nRow>=0 and nRow<n && nCol>=0 and nCol<m and image[nRow][nCol] == iniColor and ans[nRow][nCol]               != newColor) {
                dfs(nRow, nCol, image, ans, delRow, delCol, newColor, iniColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Find initial color
        int iniColor = image[sr][sc];
        
        // Modify ans array as per image array
        vector<vector<int>> ans = image;
        
        // For traversing in all the four directions.
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        // dfs call
        dfs(sr, sc, image, ans, delRow, delCol, color, iniColor);
        
        return ans;
    }
};