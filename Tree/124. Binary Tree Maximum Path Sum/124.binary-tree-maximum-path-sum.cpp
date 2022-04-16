/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int res = INT_MIN;

public:
    int maxPathSum(TreeNode *root)
    {
        helper(root);
        return res;
    }

    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};

// postorder traveral: from one node to the other,
//                  not necessary
// q1: what I got from my children
// the longest path that is straight
// q2: what process i did + what info I record + send to my parents
// @lc code=end
