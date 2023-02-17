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
    void solve(TreeNode* root , int &minDiff , int &prevVal) {
        if (root == nullptr)
            return;
        
        solve(root -> left , minDiff , prevVal);
        
        if (prevVal != -1) {
            minDiff = min(minDiff , root -> val - prevVal);
        }
        
        prevVal = root -> val;
        
        solve(root -> right , minDiff , prevVal);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prevVal = -1;
        
        solve(root , minDiff , prevVal);
        
        return minDiff;
    }
};