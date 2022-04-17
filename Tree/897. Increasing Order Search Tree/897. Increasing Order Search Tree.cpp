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
    TreeNode *increasingBST(TreeNode *root)
    {
        return helper(root);
    }

    TreeNode *helper(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->left)
        {
            TreeNode *leftNode = helper(root->left);
            TreeNode *tail = leftNode;
            while (tail->right)
                tail = tail->right;
            tail->right = root;
            root->left = nullptr;
            root->right = helper(root->right);
            return leftNode;
        }
        else
        {
            root->right = helper(root->right);
            return root;
        }
    }
};