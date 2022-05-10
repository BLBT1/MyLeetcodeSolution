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
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        auto p = helper(root, 0);
        return p.first;
    }

    // return {LCA, depth of leave}
    pair<TreeNode *, int> helper(TreeNode *root, int d)
    {
        if (root == nullptr)
            return {nullptr, d};

        auto l = helper(root->left, d + 1);
        auto r = helper(root->right, d + 1);

        if (l.second == r.second)
        {
            return {root, l.second};
        }
        else if (l.second > r.second)
            return l;
        else
            return r;
    }
};