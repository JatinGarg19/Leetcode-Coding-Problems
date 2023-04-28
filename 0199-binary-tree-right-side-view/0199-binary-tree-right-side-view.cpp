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
    void solve(TreeNode* root, int level, vector<int> &ans) {
        if(root == NULL) return;
        
        // Level becomes equal to size
        if(level == ans.size()) ans.push_back(root->val);
        
        // Recursive call to root->right
        solve(root->right, level + 1, ans);
        
        // Recursive call to root->left
        solve(root->left, level + 1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // solve(root, level, ans);
        solve(root, 0, ans);      // TC - O(N), SC - O(H).
        return ans;
    }
};