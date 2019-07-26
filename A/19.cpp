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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        int len = 0;
        while (node != NULL) {
            len++;
            node = node->next;
        }
        if (len == 0) return {};
        n = len - n;
        ListNode* nd = head;
        if (n == 0) {
            head = head->next;
        } else
            if (n == len - 1) {
                nd = nd->next;
                ListNode* prev = head;
                while (nd->next != NULL) {
                    nd = nd->next;
                    prev = prev->next;
                }
                prev->next = NULL;
            } else {
                int cnt = 1;
                ListNode* prev = head;
                nd = nd->next;
                while (nd != NULL) {
                    if (cnt == n) {
                        prev->next = nd->next;
                        break;
                    }
                    prev = prev->next;
                    nd = nd->next;
                    cnt++;
                }
            }
        
        delete nd;
        nd = NULL;
        
        return head;
    }
};
