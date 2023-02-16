/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // BASE CASE
        if(root == NULL)
            return 0;
        
        // CALL FOR LEFT AND CALCULATE DEPTH ON THE LEFT.
        int left = maxDepth(root -> left);
        
        // CALL FOR RIGHT AND CALCULATE DEPTH ON THE RIGHT.
        int right = maxDepth(root -> right);
        
        // ANS = ROOT + MAX(LEFT , RIGHT)
        int ans = 1 + max(left , right);
        
        // RETURN ANS
        return ans;
    }
};