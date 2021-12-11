/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int count = 0; // even, left->right; odd reverse order
        if (!root)
            return {};
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            vector<int> level;
            for (int i = 0; i < len; ++i)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                level.push_back(curr->val);
            }
            if (count % 2 != 0)
                reverse(level.begin(), level.end());
            ++count;
            res.push_back(level);
        }

        return res;
    }
};
// @lc code=end
