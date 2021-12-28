/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    unordered_map<TreeNode *, int> state0; // the largest for state0 at the node
    unordered_map<TreeNode *, int> state1; // the largest for state1 at the node

public:
    int rob(TreeNode *root)
    {
        // define 2 states
        // 0 <- cannot choose
        // 1 <- can choose
        return dfs(root, 1);
    }

    int dfs(TreeNode *root, int state)
    {
        if (root == nullptr)
        {
            return 0;
        }

        // if has been memorized
        if (state == 0 && state0.find(root) != state0.end())
        {
            return state0[root];
        }
        if (state == 1 && state1.find(root) != state1.end())
        {
            return state1[root];
        }

        // if hasn't been memorized
        int res = 0;
        if (state == 0)
        {
            res = dfs(root->left, 1) + dfs(root->right, 1);
            state0[root] = res;
        }
        else
        {
            int take = root->val + dfs(root->left, 0) + dfs(root->right, 0);
            int notTake = dfs(root->left, 1) + dfs(root->right, 1);
            res = max(take, notTake);
            state1[root] = res;
        }
        return res;
    }
};
// @lc code=end
