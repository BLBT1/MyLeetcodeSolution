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
        vector<vector<int>> res;
        if (root == nullptr)
            return {};
        vector<int> curr = {root->val};
        dfs(root, res, curr, root->val, targetSum);
        return res;
    }

    void dfs(TreeNode *root, vector<vector<int>> &res, vector<int> &curr, int currSum, int targetSum)
    {
        if (!root->left && !root->right)
        {
            if (currSum == targetSum)
                // cout << currSum<< endl;
                res.push_back(curr);
            else
                return;
        }

        if (root->left != nullptr)
        {
            curr.push_back(root->left->val);
            dfs(root->left, res, curr, currSum + root->left->val, targetSum);
            curr.pop_back();
        }

        if (root->right != nullptr)
        {
            curr.push_back(root->right->val);
            dfs(root->right, res, curr, currSum + root->right->val, targetSum);
            curr.pop_back();
        }
    }
};
// @lc code=end
