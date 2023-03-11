/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* constructbst(ListNode* lefthead, ListNode* righthead) {
        if(lefthead == righthead) return NULL;
        
        ListNode* slow = lefthead, *fast = lefthead;
        
        // Finding the middle node of the linked list
        while (fast != righthead && fast->next != righthead) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Making the middle node as the root.
        TreeNode *root = new TreeNode(slow->val);
        
        // Construct the left and right subtrees of the root.
        root->left = constructbst(lefthead, slow);
        root->right = constructbst(slow->next, righthead);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        // if there is no node.
        if(head == NULL) return NULL;
        
        // if there is only one node.
        if(head->next == NULL) {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        
        // func(lefthead, righthead);
        return constructbst(head, NULL);
    }
};