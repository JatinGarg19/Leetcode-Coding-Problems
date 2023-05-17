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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int maxVal = 0;
        
        // Get middle of the linked list
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // reverse second part of the linked list
        ListNode *nextNode, *prev = NULL;
        while(slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        
        // get max sum of pairs
        while(prev) {
            maxVal = max(maxVal, head->val + prev->val);
            prev = prev->next;
            head = head->next;
        }
        
        return maxVal;
    }
};