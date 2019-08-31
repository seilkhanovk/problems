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
    
    int maxToRoot(TreeNode* root, int& re) {
        if (!root) return 0;
        int l = maxToRoot(root->left, re);
        int r = maxToRoot(root->right, re);
        
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        if (l + r + root->val > re) re = root->val + l + r;
        return root->val += max(l, r);
    }
    
    int maxPathSum(TreeNode* root) {
        int re = -999999999;
        maxToRoot(root, re);
        return re;
    }
};
