class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Create a 2d matrix with all initial values as 1.
        vector<vector<int>> ans(n, vector<int>(n, 1));
        
        // Initialize left,right,top and bottom pointers
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        
        int val = 1;

        while(left <= right and top <= bottom) {
            // Print 1st row
            for(int i=left; i<=right; i++) {
                ans[top][i] = val;
                val++;
            }
            top++;

            // Print last col
            for(int i = top; i <= bottom; i++) {
                ans[i][right] = val;
                val += 1;
            }
            right--;

            // Print Last row
            for(int i = right; i >= left; i--) {
                ans[bottom][i] = val;
                val++;
            }
            bottom--;

            // Print 1st col
            for(int i = bottom; i >= top; i--) {
                ans[i][left] = val;
                val++;
            }
            left++;
            
        }

        return ans;
    }
};