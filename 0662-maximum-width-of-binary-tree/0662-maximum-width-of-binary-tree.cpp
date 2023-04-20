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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long int ans = 0;
        // queue of pair of node, index.
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            long long int size = q.size();
            // at start, cur_min will be equal to i.
            long long int cur_min = q.front().second;
            long long int leftMost, rightMost;
            
            for(int i = 0; i < size; i++) {
                // Here we are doing (i - cur_min) to prevent integer overflow but it 
                // still overflows hahahaha.
                long long int cur_id = q.front().second - cur_min;
                TreeNode* temp = q.front().first;
                q.pop();
                // Assign index to leftmost and Rightmost nodes.
                if(i == 0) leftMost = cur_id;
                if(i == size - 1) rightMost = cur_id;
                
                if(temp -> left) q.push({temp -> left, cur_id*2 + 1});
                if(temp -> right) q.push({temp -> right, cur_id*2 + 2});
            }
            
            ans = max(ans, rightMost - leftMost + 1);
        }
        // TC - O(N), SC - O(N).
        return ans;
    }
};