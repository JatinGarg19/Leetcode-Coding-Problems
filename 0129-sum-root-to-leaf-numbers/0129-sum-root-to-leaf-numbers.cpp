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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    // preorder - traversal
    int dfs(TreeNode* root, int cur) {
        if(!root) return 0;
        
        // append current node's digit.
        cur = cur * 10 + root->val;
        
        // leaf node - return current number to be added to total sum.
        if(!root->left && !root->right) {
            return cur;
        }
        
        // recurse for child if current node is not leaf.
        return dfs(root->left, cur) + dfs(root->right, cur);
    }
};