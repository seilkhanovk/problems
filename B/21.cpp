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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* head = NULL;
        if (l1->val > l2->val) {
            head = new ListNode(l2->val);
            l2 = l2->next;
        }else {
            head = new ListNode(l1->val);
            l1 = l1->next;
        }
        ListNode* node = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            }else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if (l1) node->next = l1;
        else node->next = l2;
        return head;
    }
};
