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
    int res = INT_MAX;
    TreeNode *prev = nullptr;

public:
    int getMinimumDifference(TreeNode *root)
    {
        inorder(root);
        return res;
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev == nullptr)
            prev = root;
        else
        {
            res = min(root->val - prev->val, res);
            prev = root;
        }

        inorder(root->right);
    }
};