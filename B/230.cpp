/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = root;
        int cnt = 0;
        stack<TreeNode*> st;
        while (!st.empty() || node != NULL) {
            if (node) {
                st.push(node);
                node = node->left;
            }else {
                TreeNode* curr = st.top(); st.pop();
                if (++cnt == k) return curr->val;
                node = curr->right;
            }
        }
        return -1;
    }
};
