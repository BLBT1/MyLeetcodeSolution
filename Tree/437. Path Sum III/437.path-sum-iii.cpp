/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return 0;
        return helper(root, targetSum) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }

    // calculate path sum that must start from root
    int helper(TreeNode *root, long targetSum)
    {
        if (root == nullptr)
            return 0;

        int res = 0;
        if (root->val == targetSum)
            res += 1;

        res += helper(root->left, targetSum - root->val);
        res += helper(root->right, targetSum - root->val);
        return res;
    }
};
// @lc code=end
