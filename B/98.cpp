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
    
    bool helper(TreeNode* node, TreeNode* lower, TreeNode* higher) {
        if (!node) return true;
        if (lower && lower->val >= node->val) return false;
        if (higher && higher->val <= node->val) return false;
        
        return helper(node->right, node, higher) && helper(node->left, lower, node);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};
