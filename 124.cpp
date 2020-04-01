



/* 124. 二叉树中的最大路径和
 * 
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
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
    int res = INT_MIN;
    
    int dfs(TreeNode *root) {
        if (!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);

        res = max(res, left + right + root->val);
        return max(0, max(left, right) + root->val);  // 返回对父亲节点的贡献
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};