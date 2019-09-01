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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traversal(s, t);
    }
    
    bool equals(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t || s->val != t->val) return false;
        
        return equals(s->left, t->left) && equals(s->right, t->right);
    }
    
    bool traversal(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return equals(s, t) || traversal(s->left, t) || traversal(s->right, t);
    }
};
