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
    unordered_set<TreeNode *> Set;

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes)
    {
        for (auto &node : nodes)
            Set.insert(node);
        return helper(root);
    }

    TreeNode *helper(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        if (Set.find(root) != Set.end())
            return root;

        auto l = helper(root->left);
        auto r = helper(root->right);

        if (l != nullptr && r != nullptr)
            return root;
        else if (l == nullptr)
            return r;
        else if (r == nullptr)
            return l;
        else
            return nullptr;
    }
};