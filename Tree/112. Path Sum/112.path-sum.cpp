/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        if (!root->left && !root->right && root->val == targetSum)
            return true;
        int newTar = targetSum - root->val;
        return hasPathSum(root->left, newTar) ||
               hasPathSum(root->right, newTar);
    }
};
// @lc code=end
