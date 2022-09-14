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
    vector<vector<int>> res;

public:
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        while (root != nullptr)
        {
            vector<int> leaves;
            root = removeLeaves(root, leaves);
            res.push_back(leaves);
        }
        return res;
    }

    TreeNode *removeLeaves(TreeNode *root, vector<int> &res)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(root->val);
            return nullptr;
        }

        if (root->left)
            root->left = removeLeaves(root->left, res);

        if (root->right)
            root->right = removeLeaves(root->right, res);

        return root;
    }
};
// Time: O(N^2)