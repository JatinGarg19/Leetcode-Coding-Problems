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
    ListNode* middleNode(ListNode* head) {
        //Turtle-tortoize approach
        // if there is only one node.
        if(head -> next == NULL) return head;
        // if there are only two nodes, return the second one.
        if(head -> next -> next == NULL) return head -> next;
        
        // Initially slow and fast pointers point to head
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Iterate till fast is not null or fast->next is not null
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // After coming out of the loop, return slow.
        return slow;
    }
};