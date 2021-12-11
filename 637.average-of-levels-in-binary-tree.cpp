/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        // level order traversal
        queue<TreeNode *> q;
        vector<double> res;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            double sum = 0.0;
            for (int i = 0; i < len; ++i)
            {
                sum += (double)q.front()->val;
                if (q.front()->left)
                    q.push(q.front()->left);

                if (q.front()->right)
                    q.push(q.front()->right);

                q.pop();
            } //for

            res.push_back(sum / (double)len);
        } //while

        return res;
    }
};
// @lc code=end
