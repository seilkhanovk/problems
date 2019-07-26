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
    
    void add(ListNode** headRef, int data) {
        ListNode* newNode = new ListNode(data);
        newNode->next = *headRef;
        *headRef = newNode;
    }
    
    void reorderList(ListNode* head) {
        ListNode* revHead = NULL;
        ListNode* newHead = new ListNode(0);
        ListNode* node = head;
        int len = 0;
        while (node != NULL) {
            add(&revHead, node->val);
            len++;
            node = node->next;
        }
        if (len == 0 || len == 1) return;
        node = head;
        ListNode* p = newHead;
        bool ok = true;
        int len1 = len;
        while (len--) {
            if (ok) {
                p->next = node;
                node = node->next;
                ok = !ok;
            }else {
                p->next = revHead;
                revHead = revHead->next;
                ok = !ok;
            }
            p = p->next;
        }
        p->next = NULL;
        head->next = newHead->next->next;
    }
};
