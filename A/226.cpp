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
    
    void traversal(TreeNode** nodeRef) {
        TreeNode* node = *nodeRef;
        if (!node) return;
        
        TreeNode* temp = node->left;
        (*nodeRef)->left = node->right;
        (*nodeRef)->right = temp;
        
        traversal(&(node->left));
        traversal(&(node->right));
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return {};
        traversal(&root);
        return root;
    }
};
