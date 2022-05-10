/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    int cnt = 0;

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *res = LCA(root, p, q);
        return cnt == 2 ? res : nullptr;
    }

    TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // use postorder traversal to pass info from leaves to ancestors
        if (root == nullptr)
            return nullptr;

        TreeNode *left = LCA(root->left, p, q);
        TreeNode *right = LCA(root->right, p, q);

        if (root == p || root == q)
        {
            cnt++;
            return root;
        }
        if (left != nullptr && right != nullptr)
            return root;
        else if (left == nullptr)
            return right;
        else if (right == nullptr)
            return left;
        else
            return nullptr;
    }
};