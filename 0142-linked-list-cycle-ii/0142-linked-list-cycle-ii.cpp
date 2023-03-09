/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // BASE CASE
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            // IF BOTH SLOW AND FAST COLLIDE -
            if(slow == fast) {
                
                // FIND THE 1ST NODE.
                while(slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                
                return entry;
            }
        }
        // ELSE RETURN NULL.
        return NULL;
    }
};