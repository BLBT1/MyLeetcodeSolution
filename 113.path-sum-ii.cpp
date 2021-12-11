/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> currList;
        vector<vector<int>> res;
        preorder(root, currList, targetSum, res);
        return res;
    }

    void preorder(TreeNode *root,
                  vector<int> &currList,
                  const int targetSum,
                  vector<vector<int>> &res)
    {
        if (!root)
            return;

        int newSum = targetSum - root->val;
        currList.push_back(root->val);

        if (!root->left && !root->right && root->val == targetSum)
            res.push_back(currList);

        if (root->left)
            preorder(root->left, currList, newSum, res);
        if (root->right)
            preorder(root->right, currList, newSum, res);

        currList.pop_back();
    }
};
// @lc code=end
