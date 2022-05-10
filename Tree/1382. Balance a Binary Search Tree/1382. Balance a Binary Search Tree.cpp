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
    vector<TreeNode *> nodes;

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        inorder(root);
        return helper(0, nodes.size() - 1);
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    TreeNode *helper(int beg, int end)
    {
        if (beg > end)
            return nullptr;
        int mid = beg + (end - beg) / 2;
        TreeNode *root = nodes[mid];
        root->left = helper(beg, mid - 1);
        root->right = helper(mid + 1, end);
        return root;
    }
};