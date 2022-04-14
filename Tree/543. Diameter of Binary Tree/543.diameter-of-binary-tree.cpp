/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int res = 0;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        // helper to find the depth of node
        helper(root);
        return res - 1; // num edges not nodes
    }

    int helper(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftDepth = helper(root->left);
        int rightDepth = helper(root->right);

        // 以当前node为拐点的最大路径
        res = max(res, leftDepth + rightDepth + 1);
        return max(leftDepth, rightDepth) + 1;
    }
};
// @lc code=end
