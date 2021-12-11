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
    double currMax = DBL_TRUE_MIN;

public:
    double maximumAverageSubtree(TreeNode *root)
    {
        auto currP = helper(root);
        return currMax;
    }

    // returns a pair {size of sub tree, sum of subtree}
    // do postorder traversal
    pair<int, int> helper(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        auto leftP = helper(root->left);
        auto rightP = helper(root->right);
        int subTreeSum = leftP.second + rightP.second + root->val;
        int subTreeSize = leftP.first + rightP.first + 1;
        currMax = max(currMax, double(subTreeSum) / double(subTreeSize));

        return {subTreeSize, subTreeSum};
    }
};