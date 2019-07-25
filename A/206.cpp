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
    
    void newNode(ListNode** headRef, int data) {
        ListNode* node = new ListNode(data);
        node->next = *headRef;
        *headRef = node;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* node = head;
        while (node != NULL) {
            newNode(&newHead, node->val);
            node = node->next;
        }
        return newHead;
    }
};
