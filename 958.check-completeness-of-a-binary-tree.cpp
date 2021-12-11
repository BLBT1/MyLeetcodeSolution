/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
    bool isCompleteTree(TreeNode *root)
    {
        //bfs
        // idea: from the right to the left, if we meet one null, we shoud not see any other child
        queue<TreeNode *> q;
        q.push(root);
        bool end = false;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                {
                    if (end)
                        return false;
                    q.push(curr->left);
                }
                else
                    end = true;
                if (curr->right)
                {
                    if (end)
                        return false;
                    q.push(curr->right);
                }
                else
                    end = true;
            } //for
        }     //while

        return true;
    }
};
// @lc code=end
