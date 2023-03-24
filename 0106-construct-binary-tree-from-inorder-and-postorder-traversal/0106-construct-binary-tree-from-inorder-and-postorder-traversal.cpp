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
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int &index, int instart,
                            int inend, map<int,int> &mp)
    {
        // Base Case
        if(index < 0 || instart > inend) return NULL;
        
        int elem = postorder[index--];
        
        TreeNode* root = new TreeNode(elem);
        
        int pos = mp[elem];
        
        // Recursive Calls
        root->right = constructTree(inorder, postorder, index, pos + 1, inend, mp);
        root->left = constructTree(inorder, postorder, index, instart, pos - 1, mp);
       
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        int instart = 0, inend = inorder.size() - 1;
        
        map<int,int> mp;
        
        for(int i = instart; i <= inend; i++) {
            mp[inorder[i]] = i;
        }
        
        return constructTree(inorder, postorder, index, instart, inend, mp);
        
    }
};