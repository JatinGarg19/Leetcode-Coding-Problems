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
    ListNode* sortList(ListNode* head) {
        // If there is no or single node, return null.
        if(head == NULL || head -> next == NULL) return head;
        
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Finding the middle node of the linked list
        while(fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast =  fast->next->next;
        }
        
        // End of the first left half.
        temp->next = NULL;
        
        // Left half recursive call
        ListNode* l1 = sortList(head);
        
        // right half recursive call
        ListNode* l2 = sortList(slow);
        
        // merge two sorted lists
        return merge(l1,l2);
    }
    
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode(0);
        ListNode* curr = ptr;
        
        while(l1 != NULL and l2 != NULL) {
            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
        
            curr = curr->next;
        }
        
        // for unequal length linked list
        if(l1 != NULL) {
            curr->next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL) {
            curr->next = l2;
            l2 = l2->next;
        }
        
        return ptr->next;
    }
};