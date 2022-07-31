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
    vector<string> res;

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(to_string(root->val));
        }
        else
        {
            preorder(root->left, to_string(root->val));
            preorder(root->right, to_string(root->val));
        }

        return res;
    }

    void preorder(TreeNode *root, string path)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(path + "->" + to_string(root->val));
            return;
        }

        preorder(root->left, path + "->" + to_string(root->val));
        preorder(root->right, path + "->" + to_string(root->val));
    }
};