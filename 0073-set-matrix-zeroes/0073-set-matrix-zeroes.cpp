class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // to check if any row or col is  0
        bool is_col = 0;
        bool is_row = 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // marking the rows & cols containing zeroes in 1st row & 1st col of matrix
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) { // checking if 1st col contains 0.
                is_col = true;
            }
            for(int j = 0; j < n; j++) {
                if(i == 0 and matrix[i][j] == 0) { // checking if 1st row contains 0.
                    is_row = true;
                }
                
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // first row
                    matrix[0][j] = 0;  // first col
                }
            }
        }
        
        // marking in rest of array
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // marking zeroes in 1st row
        if(is_row) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // marking zeroes in 1st col
        if(is_col) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};