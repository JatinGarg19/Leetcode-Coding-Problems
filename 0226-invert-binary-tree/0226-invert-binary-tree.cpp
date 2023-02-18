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
    TreeNode* invertTree(TreeNode* root) {
        // Base Case
        if(root == NULL)
            return NULL;
        
        queue<TreeNode*> q;
        
        // Push root to queue
        q.push(root);
        
        while(!q.empty()) {
            
            TreeNode* cur = q.front();
            
            q.pop();
            
            // Swap left child with right child
            swap(cur -> left , cur -> right);
            
            // Push left child
            if(cur -> left)
                q.push(cur -> left);
            
            // Push right child
            if(cur -> right)
                q.push(cur -> right);
        }
        
        // TC - O(N) , SC - O(H).
        return root;
    }
};