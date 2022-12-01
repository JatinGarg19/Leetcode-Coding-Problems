class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // ans vector
        vector<vector<int>> r(numRows);
        
        // Iterate from 0 to numrows
        for(int i = 0; i < numRows; i++) {
            // Each row will have i + 1 coloumns.
            r[i].resize(i + 1);
            // 1st and Last element of the row wil always be 1.
            r[i][0] = r[i][i] = 1;
            // Calculate the value of the remaning elements.
            for(int j = 1; j < i; j++) {
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j]; 
            }
        }
        return r;
    }
};