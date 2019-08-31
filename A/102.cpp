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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> tree;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> leaves;
            queue<TreeNode*> qs;
            while (!q.empty()) {
                TreeNode* node = q.front(); q.pop();
                leaves.push_back(node->val);
                if (node->left) qs.push(node->left);
                if (node->right) qs.push(node->right);
            }
            q = qs;
            tree.push_back(leaves);
        }
        return tree;
        
    }
};
