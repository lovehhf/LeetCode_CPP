
/* 653. 两数之和 IV - 输入 BST
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
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

	// 中序遍历, 左->根->右
    vector<int> inorder(TreeNode *root) {
        vector<int> res;

        stack<TreeNode *> q;
        TreeNode *cur = root;
        while(!q.empty() || cur) {
            if (cur) {
                q.push(cur);
                cur = cur->left;
            } else {
                TreeNode *node = q.top();
                q.pop();
                res.push_back(node->val);
                cur = node->right;
            }
        }
        return res;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums = inorder(root);
        int i = 0, j = nums.size() - 1;

        while(i < j) {
            if (nums[i] + nums[j] < k) i ++;
            else if (nums[i] + nums[j] > k) j --;
            else return true;
        }

        return false;
    }
};