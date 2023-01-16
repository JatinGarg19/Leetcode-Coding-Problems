//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>> &ans, int delRow[], int delCol[], int newColor, int iniColor) {
        // mark the value as newColor
        ans[row][col] = newColor;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int k = 0; k < 4; k++) {
            int nRow = row + delRow[k];
            int nCol = col + delCol[k];
            
            // If point is within the limit and has initial color and not yet made newcolor, apply dfs
            if(nRow>=0 and nRow<n && nCol>=0 and nCol<m and image[nRow][nCol] == iniColor and ans[nRow][nCol] != newColor) {
                dfs(nRow, nCol, image, ans, delRow, delCol, newColor, iniColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Find initial color
        int iniColor = image[sr][sc];
        
        // Modify ans array as per image array
        vector<vector<int>> ans = image;
        
        // For traversing in all the four directions.
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        // dfs call
        dfs(sr, sc, image, ans, delRow, delCol, newColor, iniColor);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends