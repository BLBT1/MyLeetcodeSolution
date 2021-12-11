/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode *root)
    {
        /* dfs:
        if(!root) return 0;
        if(!root->left) return minDepth(root->right)+1;
        else if(!root->right) return minDepth(root->left)+1;
         else  
        return min(minDepth(root->left), minDepth(root->right))+1;
        */
        if (!root)
            return 0;

        // bfs or level order treversal
        int depth = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (!curr->left && !curr->right)
                    return depth;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            } //for
            ++depth;
        } //while

        return depth;
    }
};
// @lc code=end
