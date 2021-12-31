/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    int findTilt(TreeNode *root)
    {
        int x = postOrder(root);
        return res;
    }

    int postOrder(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftSum = postOrder(root->left);
        int rightSum = postOrder(root->right);
        res += abs(rightSum - leftSum);
        return rightSum + leftSum + root->val;
    }
};
// @lc code=end
