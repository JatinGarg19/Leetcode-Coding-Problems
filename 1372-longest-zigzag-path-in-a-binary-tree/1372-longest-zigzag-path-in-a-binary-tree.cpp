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
    int maxStep = 0;
public:
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        
        return maxStep;
    }
    
    void dfs(TreeNode* root, bool isLeft, int step) {
        if(!root) return;
        
        // update maxStep so far
        maxStep = max(maxStep, step);
        
        if(isLeft) {
            // keep going from root to left
            dfs(root->left, false, step+1);
            // restart going from root to right
            dfs(root->right, true, 1);
        } else {
            // keep going from root to right
            dfs(root->right, true, step+1);
            // restart going from root to left
            dfs(root->left, false, 1);
        }
    }
};