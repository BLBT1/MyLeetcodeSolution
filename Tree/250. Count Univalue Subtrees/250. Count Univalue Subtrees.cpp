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
    int res = 0;

public:
    int countUnivalSubtrees(TreeNode *root)
    {
        helper(root);
        return res;
    }
    bool helper(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        bool left = helper(root->left);
        bool right = helper(root->right);
        if (left && right)
        {
            if (root->left && root->val != root->left->val)
                return false;
            if (root->right && root->val != root->right->val)
                return false;
            res += 1;
            return true;
        }
        return false;
    }
};