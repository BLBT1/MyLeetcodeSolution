/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        return inorder(root, low, high);
    }

    TreeNode *inorder(TreeNode *root, int low, int high)
    {
        if (!root)
            return nullptr;
        TreeNode *leftTrimmed;
        TreeNode *rightTrimmed;
        if (root->val < low)
        {
            return inorder(root->right, low, high);
        }
        else if (root->val > high)
            return inorder(root->left, low, high);
        else
        {
            leftTrimmed = inorder(root->left, low, high);
            rightTrimmed = inorder(root->right, low, high);
            root->left = leftTrimmed;
            root->right = rightTrimmed;
        }

        return root;
    }
};
// @lc code=end
