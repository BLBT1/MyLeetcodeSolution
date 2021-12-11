/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    int currFrq = 0; // the curr element frequency
    int maxFrq = 0;  // the max frq
    int prev = 0;    // the prev element
    vector<int> res; // the final result set

public:
    // in bst, whenever order matters, we use inorder traversal
    vector<int> findMode(TreeNode *root)
    {
        inorder(root);
        return res;
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        // do things
        if (maxFrq == 0)
        {
            currFrq = maxFrq = 1;
            res = {root->val};
        }
        else
        {
            if (root->val == prev)
            {
                currFrq++;
                if (currFrq > maxFrq)
                {
                    res = {root->val};
                    maxFrq = currFrq;
                }
                else if (currFrq == maxFrq)
                {
                    res.push_back(root->val);
                }
            }
            else
            {
                currFrq = 1;
                if (currFrq == maxFrq)
                {
                    res.push_back(root->val);
                }
            }
        }
        prev = root->val;

        inorder(root->right);
    }
};
// @lc code=end
