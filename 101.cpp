
/*
 * 101. 对称二叉树
 *
 * 判断左子树和右子树是否是镜像的
 */

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
    bool is_mirror(TreeNode *root1, TreeNode *root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2 || root1->val != root2->val) return false;
        return is_mirror(root1->left, root2->right) && is_mirror(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return is_mirror(root->left, root->right);
    }
};