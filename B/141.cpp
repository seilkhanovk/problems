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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* node = head;
        ListNode* fastNode = head->next;
        while (node != fastNode) {
            if (fastNode == NULL || fastNode->next == NULL) return false;
            node = node->next;
            fastNode = fastNode->next->next;
        }
        return true;
    }
};
