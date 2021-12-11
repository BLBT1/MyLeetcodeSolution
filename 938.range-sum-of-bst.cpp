/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;05
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int sum = 0;

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        helper(root, low, high);
        return sum;
    }

    void helper(TreeNode *root, int low, int high)
    {
        if (!root)
            return;
        else if (root->val <= high && root->val >= low)
        {
            sum += root->val;
            helper(root->left, low, high);
            helper(root->right, low, high);
        }
        else if (root->val < low)
            helper(root->right, low, high);
        else if (root->val > high)
            helper(root->left, low, high);
    }
};
// @lc code=end
