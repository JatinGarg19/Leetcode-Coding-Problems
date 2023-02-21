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
class Solution {
public:
    // Iterative Solution - TC - O(N) , SC - O(1). 
    ListNode* solve(ListNode* head) {
        // A temp pointer to traverse the linked list.
        ListNode* temp = head;
        
        // Traverse the list
        while(temp != NULL && temp -> next != NULL) {
            // Swap
            swap(temp -> val, temp -> next -> val);
            
            // Update Temp.
            temp = temp -> next -> next;
        }
        
        return head;
    }
    
    ListNode* swapPairs(ListNode* head) {
        //return solve(head);
        
        if(head != NULL && head->next != NULL) {
            swap(head->val , head->next->val);
            
            swapPairs(head->next->next);
        }
        
        return head;
    }
};