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
    
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return {};
        if ((root->val > p->val && root->val < q->val) || root->val == p->val || root->val == q->val) return root;
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);else
            return lowestCommonAncestor(root->right, p, q);
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < q->val) return traversal(root, p, q);
        return traversal(root, q, p);
    }
};
