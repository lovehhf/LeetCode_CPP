

/* 543. 二叉树的直径
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/
 */ 


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int res = 0;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        
        // 左右子树的最大直径
        int left = dfs(root->left);
        int right = dfs(root->right);

        res = max(res, left + right);
        
        // 返回该节点对它父亲贡献的节点个数
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};