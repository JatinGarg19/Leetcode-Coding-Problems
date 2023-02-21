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
    ListNode* swapPairs(ListNode* head) {
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
};