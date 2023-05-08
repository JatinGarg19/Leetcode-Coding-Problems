class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        
        int mid = n / 2;
        
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            // primary diagonal
            sum += mat[i][i];
            
            // secondary diagonal
            sum += mat[n-1-i][i];
        }
        
        if(n % 2 == 1) {
            sum -= mat[mid][mid];
        }
        
        return sum;
    }
};