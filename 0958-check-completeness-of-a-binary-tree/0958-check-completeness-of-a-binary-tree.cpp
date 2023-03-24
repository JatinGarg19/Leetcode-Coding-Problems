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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        
        bool isNull = false;
        
        while (!q.empty()) {
            int totalNodesInLevel = q.size();
            
            while (totalNodesInLevel--) {
                TreeNode *cur = q.front(); q.pop();
                
                if (cur == NULL) {
                    isNull = true;
                }
                else {
                    if (isNull == true) {
                        return false;
                    }
                    
                    q.push(cur -> left);
                    q.push(cur -> right);
                }
            }
        }
        
        return true;  // Tc - O(n) , Sc - O(n).
    }
};