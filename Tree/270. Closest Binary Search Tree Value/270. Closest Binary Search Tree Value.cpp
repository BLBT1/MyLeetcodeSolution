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
    int res;
    double curr;

public:
    int closestValue(TreeNode *root, double target)
    {
        res = root->val;
        curr = abs(root->val - target);
        helper(root, target);
        return res;
    }

    void helper(TreeNode *root, double target)
    {
        if (root == nullptr)
            return;

        if (abs(root->val - target) < curr)
        {
            curr = abs(root->val - target);
            res = root->val;
        }

        if (target > double(root->val))
        {
            helper(root->right, target);
        }
        else
        {
            helper(root->left, target);
        }
    }
};