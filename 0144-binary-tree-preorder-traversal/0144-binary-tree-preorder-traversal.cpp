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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL) {
            // 1ST CASE
            if(curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            // 2ND CASE
            else {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {
                    // CREATE A THREAD
                    prev->right = curr;
                    // FOR PREORDER
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    // REMOVE THE CREATED THREAD
                    prev->right = NULL;
                    
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};