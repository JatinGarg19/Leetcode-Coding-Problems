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
    bool symmetricUtil(TreeNode* root1, TreeNode* root2) {
        // If any one is null, check for equality.
        if(root1 == NULL || root2 == NULL) return (root1 == root2);
        
        // If both nodes  have a certain value -
        // returns true if all the three cond'n return true, else it returns false.
        return (root1->val == root2->val) && symmetricUtil(root1->left, root2->right) && 
                symmetricUtil(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        // if root is null, it is always considered as symmetric.
        if(root == NULL) return true;
        
        return symmetricUtil(root->left, root->right);
    }
};