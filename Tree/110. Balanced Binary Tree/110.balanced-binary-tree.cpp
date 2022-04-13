/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

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
public:
    bool isBalanced(TreeNode *root)
    {
        return helper(root) != -1;
    }

    // a helper return the depth of the tree
    // if return -1, then the tree is already not balanced
    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int depthLeft = helper(root->left);
        int depthRight = helper(root->right);

        // if any left subtree or right subree is inbalanced,
        // the entire tree is already not balanced
        if (depthLeft == -1 || depthRight == -1)
            return -1;

        if (abs(depthLeft - depthRight) > 1)
            return -1;

        return max(depthLeft, depthRight) + 1;
    }
};
// @lc code=end
