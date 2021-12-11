/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return dfs(1, n);
    }

    // return all the possible bst in the closed range [begin, end]
    // 5,5 6,5 5,4
    vector<TreeNode *> dfs(int begin, int end)
    {
        if (begin > end)
        {
            return {NULL};
        }
        vector<TreeNode *> subTree;

        for (int i = begin; i <= end; ++i)
        {
            auto leftSubTree = dfs(begin, i - 1);
            auto rightSubTree = dfs(i + 1, end);

            // idea: use multi rule to find form all possible bst
            for (int j = 0; j < leftSubTree.size(); ++j)
                for (int k = 0; k < rightSubTree.size(); ++k)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = leftSubTree[j];
                    node->right = rightSubTree[k];
                    subTree.push_back(node);
                }
        } // for

        return subTree;
    }
};
// @lc code=end
