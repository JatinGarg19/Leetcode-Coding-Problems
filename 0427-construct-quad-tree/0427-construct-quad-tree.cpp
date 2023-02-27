/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>>& grid, int rowstart, int rowend, int colstart, int colend) {
        // EDGE CASE
        if(rowstart > rowend || colstart > colend) return NULL;
        
        // CHECK IF ALL ELEMENTS IN THE QUADRANT ARE THE SAME
        bool isleaf = true;
        int value = grid[rowstart][colstart];
        
        for(int i = rowstart; i <= rowend; i++) {
            for(int j = colstart; j <= colend; j++) {
                if(grid[i][j] != value) {
                    isleaf = false;
                    break;
                }
            }
            
            if(!isleaf) {
                break;
            }
        }
        
        // CREATE A LEAF NODE IF ALL ELEMENTS IN THE QUADRANT ARE SAME.
        if(isleaf) {
            return new Node(value, true);
        }
        
        // OTHERWISE, DIVIDE THE QUADRANT INTO 4 SUB QUADRANTS AND RECURSIVELY CONSTRUCT THE QUAD TREE
        // FOR EACH SUB-QUADRANT.
        int rowmid = (rowstart + rowend) / 2;
        int colmid = (colstart + colend) / 2;
        
        Node* topLeft = solve(grid, rowstart, rowmid, colstart, colmid);
        
        Node* topRight = solve(grid, rowstart, rowmid, colmid + 1, colend);
        
        Node* bottomLeft = solve(grid, rowmid + 1, rowend, colstart, colmid);
        
        Node* bottomRight = solve(grid, rowmid + 1, rowend, colmid + 1, colend);
        
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        
        return solve(grid, 0, n - 1, 0, n - 1);
    }
};