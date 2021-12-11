// Common #includes for convience.
// No need to use them.
// Remove any of them if you want.

using namespace std;

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
    int res;

    //* time: O(n); space O(h) // size of stack
    //* this is a helper function recursively
    //* return the longest path of the left or the right child
    //* meanwhile, also update the diameter if it is the root
    int LongestPath(TreeNode *root)
    {
        if (!root)
            return -1;
        int leftLongest = LongestPath(root->left) + 1; //* +1 for the e(root,leftchild)
        int rightLongest = LongestPath(root->right) + 1;
        //* update the res if the node is the turnover
        res = max(res, leftLongest + rightLongest);
        return max(leftLongest, rightLongest);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        res = 0;
        LongestPath(root);
        return res;
    }
};
// @lc code=end
