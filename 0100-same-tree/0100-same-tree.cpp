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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are null, return true.
        if(p == NULL && q == NULL) return true;
        
        // If any one is null, return false.
        if((p != NULL && q == NULL) || (p == NULL && q != NULL)) return false;
        
        // Rrecursive left call
        bool left = isSameTree(p->left, q->left);
        // Recursive right call
        bool right = isSameTree(p->right, q->right);
        
        bool value = (p->val == q->val);
        
        // If all the 3 conditions are true, return true else return false.
        if(left && right && value) return true;
        
        else return false;
    }
};