class Solution {
public:
    bool searchNext(vector<vector<char>>& board, string word, int row, int col, int idx) {
        int m = board.size();
        int n = board[0].size();
        
        // If idx reaches the end, that means we have found the word.
        if(idx == word.length())
            return true;
        
        /* Checking the boundaries if the character at which we are placed is not the required              character */
        if(row < 0 or col < 0 or row == m or col == n or board[row][col] != word[idx] or                    board[row][col] == '!')
            return false;

        // this is to prevent reuse of the same character
        char ch = board[row][col];
        board[row][col] = '!';
        
        // top direction
        bool top = searchNext(board, word, row-1, col, idx+1);
        
        // right direction
        bool right = searchNext(board, word, row, col+1, idx+1);
        
        // bottom direction
        bool bottom = searchNext(board, word, row+1, col, idx+1);
        
        // left direction
        bool left = searchNext(board, word, row, col-1, idx+1);
        
        // Undo change
        board[row][col] = ch;
        
        return top or right or bottom or left;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();   // row length
        int n = board[0].size();   // colomn length
        
        int idx = 0;
        
        // First search the first character.
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[idx]) {
                    if(searchNext(board , word , i , j , idx))
                        return true;
                }
            }
        }
        
        return false;
    }
};