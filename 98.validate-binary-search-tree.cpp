/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    // 这个题思维很好想 但是写起来不容易
    // 要把当前点的范围转递下去 [min, max]
    // if the node->val not in this range, also return false
    bool isValidBST(TreeNode *root)
    {
        return helper(root, INT_MIN, INT_MAX);
    }

    bool helper(TreeNode *root, long long min, long long max)
    {
        if (!root)
            return true;
        if (root->val < min || root->val > max)
            return false;
        return helper(root->left, min, (long long)root->val - 1) &&
               helper(root->right, (long long)root->val + 1, max);
    }
};
// @lc code=end
