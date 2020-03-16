
/* 144. 二叉树的前序遍历
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 *
 * 使用栈模拟
 * 从根节点开始，每次迭代弹出当前栈顶元素，并将其孩子节点压入栈中，先压右孩子再压左孩子。
 *
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode *cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
        }

        return res;
    }
};